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

int64_t calc1(int64_t x) {
	// 桁DP
	string s = to_string(x);
	int64_t dp[20][2][2] = { 1 };
	for (size_t i = 0; i < s.length(); ++i) {
		int d = s[i] - '0';
		for (int j = 0; j < 2; ++j) {		// 未満フラグ
			for (int k = 0; k < 2; ++k) {		// 禁止フラグ
				for (int l = 0; l <= (j ? 9 : d); ++l) {
					dp[i + 1][j || l < d][k || l == 4 || l == 9] += dp[i][j][k];
				}
			}
		}
	}
	return dp[s.size()][0][1] + dp[s.size()][1][1];
}

int64_t calc(int64_t x) {
	// 桁DP
	string s = to_string(x);
	auto dp = vector(20, vector(10, int64_t(0)));
	bool p = false;
	for (size_t i = 0; i < s.length(); ++i) {
		int d = s[i] - '0';
		for (int k = 0; k < 2; ++k) {		// 禁止フラグ
			for (int l = 0; l <= 9; ++l) {
				dp[i + 1][k || l == 4 || l == 9] += dp[i][k];
			}
		}
		if (i > 0) {
			for (int l = 1; l <= 9; ++l) {
				dp[i + 1][l == 4 || l == 9] += 1;
			}
		}
		for (int l = 0; l < d; ++l) {
			if (i > 0 || l > 0) {
				dp[i + 1][p || l == 4 || l == 9] += 1;
			}
		}
		p |= d == 4 || d == 9;
	}
	return dp[s.size()][1] + p;
}

int64_t solve(int64_t A, int64_t B) {
	return calc(B) - calc(A - 1);
}

int main() {
	int64_t A, B;
	std::cin >> A >> B;
	cout << solve(A, B) << endl;
	return 0;
}
