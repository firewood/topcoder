#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

int main(int argc, char *argv[])
{
	LL N;
	cin >> N;
	LL dp[2][3] = {};
	dp[0][0] = 1;
	for (int t = 0; t < N; ++t) {
		int prev = t & 1;
		int next = prev ^ 1;
		dp[next][0] = (dp[prev][1] + dp[prev][2]) % MOD;
		dp[next][1] = dp[prev][0];
		dp[next][2] = dp[prev][1];
	}
	LL ans = (dp[N & 1][0] + dp[N & 1][1] + dp[N & 1][2]) % MOD;
	cout << ans << endl;
	return 0;
}
