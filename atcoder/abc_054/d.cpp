// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		const int INF = 1 << 30;
		int n = -1, ma, mb, a, b, c;
		cin >> n >> ma >> mb;
		if (n < 0) return 0;
		vector<vector<int>> dp(2001, vector<int>(2001, INF));
		dp[0][0] = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b >> c;
			for (int i = 2000; i >= a; --i) {
				for (int j = 2000; j >= b; --j) {
					dp[i][j] = min(dp[i][j], dp[i - a][j - b] + c);
				}
			}
		}
		int ans = INF;
		for (a = ma, b = mb; a <= 2000 && b <= 2000; a += ma, b += mb) {
			ans = min(ans, dp[a][b]);
		}
		cout << (ans < INF ? ans : -1) << endl;
	}
	return 0;
}
