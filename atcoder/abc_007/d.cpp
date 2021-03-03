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

long long calc(long long x) {
	// 桁DP
	string s = to_string(x);
	long long dp[20][2][2] = { 1 };
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

long long solve(long long A, long long B) {
	return calc(B) - calc(A - 1);
}

int main() {
    long long A, B;
	std::cin >> A >> B;
	cout << solve(A, B) << endl;
	return 0;
}
