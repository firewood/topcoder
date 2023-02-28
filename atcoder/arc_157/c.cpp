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
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint998244353;

mint solve(int64_t H, int64_t W, std::vector<std::string> S) {
	static const size_t COMBSZ = 4004;
	vector<vector<mint>> C(COMBSZ, vector<mint>(COMBSZ));
	for (int i = 0; i < COMBSZ; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	mint ans = 0;
	vector<vector<mint>> dp(H + 2, vector<mint>(W + 2, 0));
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
			if (S[i][j] == 'Y') {
				if (i > 0 && S[i - 1][j] == 'Y') {
					dp[i + 1][j + 1] += C[i + j - 1][i - 1];
					ans += (C[i + j - 1][i - 1] + dp[i][j + 1] * 2) * C[H + W - i - j - 2][H - i - 1];
				}
				if (j > 0 && S[i][j - 1] == 'Y') {
					dp[i + 1][j + 1] += C[i + j - 1][i];
					ans += (C[i + j - 1][i] + dp[i + 1][j] * 2) * C[H + W - i - j - 2][H - i - 1];
				}
			}
		}
	}
	return ans;
}

int main() {
	int64_t H, W;
	std::cin >> H >> W;
	std::vector<std::string> S(H);
	for (int i = 0; i < H; i++) {
		std::cin >> S[i];
	}
	cout << solve(H, W, S).val() << endl;
	return 0;
}
