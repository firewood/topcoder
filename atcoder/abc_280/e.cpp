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

mint solve(int N, int P) {
	mint ans = 0, p = mint(P) / 100;
	vector<mint> dp(N + 2);
	dp[0] = 1;
	for (int i = 0; i < N; ++i) {
		dp[i + 2] += dp[i] * p;
		dp[i + 1] += dp[i] * (1 - p);
		ans += dp[i + 1];
	}
	return accumulate(dp.begin() + 1, dp.end(), mint(0));
}

int main() {
	int N, P;
	std::cin >> N >> P;
	cout << solve(N, P).val() << endl;
	return 0;
}
