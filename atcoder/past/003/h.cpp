// H.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

int main() {
	int n, l, x, t[3];
	cin >> n >> l;
	vector<int> dp(100006), dp2(100006, 1 << 30), h(100006);
	for (int i = 0; i < n; ++i) {
		cin >> x;
		h[x] = 1;
	}
	for (int i = 0; i < 3; ++i) {
		cin >> t[i];
	}
	dp[0] = 0;
	dp2[0] = 0;
	for (int i = 1; i < l + 4; ++i) {
		dp[i] = dp[i - 1] + t[0] + h[i] * t[2];
		if (i < 2) continue;
		dp2[i - 1] = min(dp2[i - 1], dp[i - 2] + (t[0] + t[1]) / 2);
		dp[i] = min(dp[i], dp[i - 2] + t[0] + t[1] + h[i] * t[2]);
		if (i < 4) continue;
		dp2[i - 3] = min(dp2[i - 3], dp[i - 4] + (t[0] + t[1]) / 2);
		dp2[i - 2] = min(dp2[i - 2], dp[i - 4] + (t[0] + t[1] * 3) / 2);
		dp2[i - 1] = min(dp2[i - 1], dp[i - 4] + (t[0] + t[1] * 5) / 2);
		dp[i] = min(dp[i], dp[i - 4] + t[0] + t[1] * 3 + h[i] * t[2]);
	}
	cout << min(dp[l], dp2[l]) << endl;
	return 0;
}
