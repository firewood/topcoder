// B. 

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
const int MOD = 1000000007;

int main(int argc, char *argv[])
{
	int N, D[100000], dp[6][100000] = {};
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> D[i];
		dp[0][i] = 1;
	}

	if (N > 3000) {
		cout << "-1" << endl;
		return 0;
	}

	sort(D, D + N);
	for (int i = 1; i <= 3; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < j; ++k) {
				if (D[k] * 2 > D[j]) {
					break;
				}
				dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		ans = (ans + dp[3][i]) % MOD;
	}
	cout << ans << endl;
	return 0;
}
