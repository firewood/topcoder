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

std::vector<string> solve(int64_t H, int64_t W, int64_t Q, vector<int64_t> R, vector<int64_t> C, vector<string> X) {
	std::vector<string> ans(H, string(W, '.'));
	auto dfs = [&](auto dfs_, int r, int c, char ch) -> void {
		if (r >= 0 && c >= 0 && ans[r][c] == '.') {
			ans[r][c] = ch;
			dfs_(dfs_, r, c - 1, ch);
			dfs_(dfs_, r - 1, c, ch);
		}
	};
	for (int qi = Q - 1; qi >= 0; --qi) {
		dfs(dfs, R[qi] - 1, C[qi] - 1, X[qi][0]);
	}
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (ans[i][j] == '.') {
				ans[i][j] = 'A';
			}
		}
	}
	return ans;
}

int main() {
	int64_t H, W, Q;
	cin >> H >> W >> Q;
	vector<int64_t> R(Q), C(Q);
	vector<string> X(Q);
	for (int64_t i = 0; i < Q; ++i) {
		cin >> R[i] >> C[i] >> X[i];
	}
	auto answers = solve(H, W, Q, R, C, X);
	for (const auto ans : answers) {
		cout << ans << endl;
	}
}
