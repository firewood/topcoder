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

int64_t solve(int64_t N) {
	int64_t ans = 0;
	string s = to_string(N);
	int64_t dp[20][2][20][2] = { 0 };		// [桁][未満フラグ][連続数][最後が1]
	for (size_t i = 0; i < s.length(); ++i) {
		int64_t d = s[i] - '0';
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 19; ++k) {
				for (int l = 0; l < 2; ++l) {
					if (j) {
						dp[i + 1][j][k][0] += dp[i][j][k][l] * 10;
					} else {
						dp[i + 1][j][k][0] += dp[i][j][k][l];
						dp[i + 1][1][k][0] += dp[i][j][k][l] * d;
					}
				}
				if (j || d >= 1) {
					dp[i + 1][j || d > 1][k + 1][1] += dp[i][j][k][1];
				}
			}
		}
		dp[i + 1][i >= 1 || d > 1][1][1] += 1;
	}
	for (int j = 0; j < 2; ++j) {
		for (int k = 1; k < 20; ++k) {
			for (int l = 0; l < 2; ++l) {
				ans += dp[s.length()][j][k][l];
			}
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
