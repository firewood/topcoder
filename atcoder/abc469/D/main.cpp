#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int64_t solve(int64_t N, int64_t M, vector<int> A, vector<int> B) {
	set<II> ans;
	auto enumerate = [&](int x) {
		for (int i = 0; i < M; ++i) {
			int a = A[i], b = B[i];
			if (x != a && x != b) {
				vector<int> s1({min(a, b), max(a, b)});
				for (int j = i + 1; j < M; ++j) {
					int a = A[j], b = B[j];
					if (x != a && x != b) {
						vector<int> s2({min(a, b), max(a, b)});
						vector<int> res;
						set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(res, res.end()));
						s1 = res;
					}
				}
				for (auto y : s1) {
					ans.insert(II(min(x, y), max(x, y)));
				}
				return;
			}
		}
		for (int y = 1; y <= N; ++y) {
			if (y != x) {
				ans.insert(II(min(x, y), max(x, y)));
			}
		}
	};
	enumerate(A[0]);
	enumerate(B[0]);
	return ans.size();
}

int main() {
	int64_t N, M;
	cin >> N >> M;
	vector<int> A(M), B(M);
	for (int64_t i = 0; i < M; ++i) {
		cin >> A[i] >> B[i];
	}
	auto ans = solve(N, M, A, B);
	cout << ans << endl;
}
