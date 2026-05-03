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
typedef long double LD;

LD solve(vector<vector<int64_t>> A) {
	LD ans = 0;
	vector<int> seq({4,5,6});
	do {
		LD p = 1.0 / 6 / 6 / 6;
		for (int64_t i = 0; i < 3; ++i) {
			int cnt = 0;
			for (int64_t j = 0; j < 6; ++j) {
				if (A[i][j] == seq[i]) {
					++cnt;
				}
			}
			p *= cnt;
		}
		ans += p;
	} while (next_permutation(seq.begin(), seq.end()));
	return ans;
}

int main() {
	cout.precision(20);
	vector<vector<int64_t>> A(3, vector<int64_t>(6));
	for (int64_t i = 0; i < 3; ++i) {
		for (int64_t j = 0; j < 6; ++j) {
			cin >> A[i][j];
		}
	}
	auto ans = solve(A);
	cout << ans << endl;
}
