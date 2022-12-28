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

mint solve(int64_t N, std::string S) {
	mint ans = 0;
	vector<vector<mint>> dp(27, vector<mint>(27, 0));
	dp[26][26] = 1;
	for (char ch : S) {
		vector<vector<mint>> next(27, vector<mint>(27, 0));
		for (int a = 0; a < 27; ++a) {
			for (int b = 0; b < 27; ++b) {
				int st, ed;
				if (ch == '?') {
					st = 0, ed = 25;
				} else {
					st = ed = ch - 'a';
				}
				for (int c = st; c <= ed; ++c) {
					if (a == c || b == c) continue;
					if (dp[a][b].val() == 0) continue;
					next[b][c] += dp[a][b];
				}
			}
		}
		dp = next;
	}
	for (int a = 0; a < 27; ++a) {
		for (int b = 0; b < 27; ++b) {
			ans += dp[a][b].val();
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::string S;
	std::cin >> N >> S;
	cout << solve(N, S).val() << endl;
	return 0;
}
