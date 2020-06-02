// K.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<LL> c(n), d(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	vector<LL> dp(1);
	for (int i = 0; i < n; ++i) {
		vector<LL> next(i + 2, 1LL << 60);
		if (s[i] == '(') {
			for (int j = 0; j <= i + 1; ++j) {
				LL m = 1LL << 60;
				if (j <= i) {
					m = min(m, dp[j] + d[i]);
				}
				if (j > 0) {
					m = min(m, dp[j - 1]);
				}
				if (j < i) {
					m = min(m, dp[j + 1] + c[i]);
				}
				next[j] = m;
			}
		} else {
			for (int j = 0; j <= i + 1; ++j) {
				LL m = 1LL << 60;
				if (j <= i) {
					m = min(m, dp[j] + d[i]);
				}
				if (j > 0) {
					m = min(m, dp[j - 1] + c[i]);
				}
				if (j < i) {
					m = min(m, dp[j + 1]);
				}
				next[j] = m;
			}
		}
		dp = next;
	}
	LL ans = dp[0];
	cout << ans << endl;
	return 0;
}
