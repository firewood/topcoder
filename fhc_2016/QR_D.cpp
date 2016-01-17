
// Facebook Hacker Cup 2016 Qualification Round
// D. Text Editor
//

#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int common_length(const string &a, const string &b) {
	size_t m = min(a.length(), b.length());
	size_t len;
	for (len = 0; len < m; ++len) {
		if (a[len] != b[len]) {
			break;
		}
	}
	return len;
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, K;
		cin >> N >> K;
		vector<string> w;
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			w.push_back(s);
		}
		sort(w.begin(), w.end());

		int dp[302][302];
		memset(dp, 0x3f, sizeof(dp));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < i; ++j) {
				int l = common_length(w[i], w[j]);
				for (int k = 1; k <= i && k < K; ++k) {
					int cost = dp[j][k] + (w[i].length() - l) * 2;
					dp[i][k + 1] = min(dp[i][k + 1], cost);
				}
			}
			dp[i][1] = w[i].length() * 2;
		}

		int ans = 1 << 30;
		for (int i = K - 1; i < N; ++i) {
			ans = min(ans, dp[i][K]);
		}
		ans += K;

		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
