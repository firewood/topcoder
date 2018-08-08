// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int d, g, tot = 0;
	cin >> d >> g;
	static int dp[11][1111];
	for (int i = 0; i < d; ++i) {
		int p, c;
		cin >> p >> c;
		for (int j = 0; j <= tot; ++j) {
			for (int k = 0; k < p; ++k) {
				dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + k * (i + 1) * 100);
			}
			dp[i + 1][j + p] = max(dp[i + 1][j + p], dp[i][j] + p * (i + 1) * 100 + c);
		}
		tot += p;
	}
	int ans = 1 << 30;
	for (int i = 0; i <= tot; ++i) {
		if (dp[d][i] >= g) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
