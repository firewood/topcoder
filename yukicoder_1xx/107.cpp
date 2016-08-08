#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	int d[16], mhp[65536] = { 100 };
	for (int i = 0; i < N; ++i) {
		cin >> d[i];
	}
	for (int i = 1; i < (1 << N); ++i) {
		for (int j = 0; j < N; ++j) {
			if (i & (1 << j)) {
				mhp[i] = mhp[i - (1 << j)] + (d[j] < 0 ? 100 : 0);
				break;
			}
		}
	}
	int dp[65536] = { 100 };
	for (int i = 0; i < (1 << N); ++i) {
		if (dp[i]) {
			for (int j = 0; j < N; ++j) {
				if (!(i & (1 << j))) {
					int x = min(dp[i] + d[j], mhp[i + (1 << j)]);
					dp[i + (1 << j)] = max(dp[i + (1 << j)], x);
				}
			}
		}
	}
	cout << dp[(1 << N) - 1] << endl;
	return 0;
}
