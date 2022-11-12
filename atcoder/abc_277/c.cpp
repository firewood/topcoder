#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

int solve(int N, std::vector<int> A, std::vector<int> B) {
	int ans = 1;
	map<int, vector<int>> m;
	for (int i = 0; i < N; ++i) {
		m[A[i]].emplace_back(B[i]);
		m[B[i]].emplace_back(A[i]);
	}
	set<int> vis;
	vector<int> q;
	q.emplace_back(1);
	vis.insert(1);
	while (!q.empty()) {
		vector<int> nq;
		for (auto x : q) {
			ans = max(ans, x);
			for (auto y : m[x]) {
				if (vis.find(y) == vis.end()) {
					vis.insert(y);
					nq.emplace_back(y);
				}
			}
		}
		q = nq;
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	cout << solve(N, A, B) << endl;
	return 0;
}
