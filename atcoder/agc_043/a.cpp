// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
	int h = -1, w;
	cin >> h >> w;
	vector<string> b(h);
	for (int i = 0; i < h; ++i) {
		cin >> b[i];
	}
	int dp[102][102][2] = {};
	memset(dp, 0x3f, sizeof(dp));
	dp[0][1][0] = 0, dp[0][1][1] = 1;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			int is_black = b[i][j] != '.';
			dp[i + 1][j + 1][is_black] = min({
				dp[i][j + 1][0] + is_black, 
				dp[i][j + 1][1],
				dp[i + 1][j][0] + is_black,
				dp[i + 1][j][1]
			});
		}
	}
	cout << min(dp[h][w][0], dp[h][w][1]) << endl;
	return 0;
}
