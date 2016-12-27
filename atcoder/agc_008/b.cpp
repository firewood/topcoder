// B. 

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int N, K;
	cin >> N >> K;
	LL A[100000], sum[100001] = {}, msum[100001] = {}, dp[100000][3] = {};
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		sum[i + 1] = sum[i] + A[i];
		msum[i + 1] = msum[i] + max(0LL, A[i]);
	}
	dp[K-1][0] = 0;
	dp[K-1][1] = 0;
	dp[K-1][2] = sum[K];
	for (int i = K; i < N; ++i) {
		dp[i][0] = max({ dp[i - 1][0], dp[i - 1][1], dp[i - 1][2] });
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + A[i];
		dp[i][1] = max(dp[i][1], msum[i + 1 - K]);
		dp[i][2] = max(dp[i][2], msum[i + 1 - K] + sum[i + 1] - sum[i + 1 - K]);
	}
	LL ans = max({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });
	cout << ans << endl;
	return 0;
}
