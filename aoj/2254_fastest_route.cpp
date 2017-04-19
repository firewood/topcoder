#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	while (true) {
		int n;
		cin >> n;
		if (!n) {
			break;
		}
		int z[16];
		int cost[16][16];
		for (int i = 0; i < n; ++i) {
			cin >> z[i];
			for (int j = 0; j < n; ++j) {
				cin >> cost[i][j];
			}
		}
		int dp[1 << 16];
		memset(dp, 0x3f, sizeof(dp));
		dp[0] = 0;
		int m = 1 << n;
		for (int b = 0; b < m; ++b) {
			for (int i = 0; i < n; ++i) {
				if (!(b & (1 << i))) {
					int c = z[i];
					for (int j = 0; j < n; ++j) {
						if (b & (1 << j)) {
							c = min(c, cost[i][j]);
						}
					}
					dp[b | (1 << i)] = min(dp[b | (1 << i)], dp[b] + c);
				}
			}
		}
		cout << dp[m - 1] << endl;
	}
	return 0;
}
