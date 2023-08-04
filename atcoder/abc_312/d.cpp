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

mint solve(std::string S) {
	vector<mint> dp(3002, 0);
	dp[0] = 1;
	for (char c : S) {
		vector<mint> next(3002, 0);
		if (c == '(' || c == '?') {
			for (int i = 0; i < 3000; ++i) {
				next[i + 1] = dp[i];
			}
		}
		if (c == ')' || c == '?') {
			for (int i = 0; i < 3000; ++i) {
				next[i] += dp[i + 1];
			}
		}
		dp = next;
	}
	return dp[0];
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif
	std::string S;
	std::cin >> S;
	cout << solve(S).val() << endl;
	return 0;
}
