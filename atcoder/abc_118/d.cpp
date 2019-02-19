// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	int p[10] = {};
	for (int i = 0; i < m; ++i) {
		int a;
		cin >> a;
		p[a] = 1;
	}
	vector<string> dp(n + 1);
	int tbl[] = { 0, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
	for (int d = 9; d >= 1; --d) {
		if (p[d]) {
			for (int i = n; i >= tbl[d]; --i) {
				if (i == n || !dp[i].empty()) {
					string s = dp[i] + char('0' + d);
					if (s.length() > dp[i - tbl[d]].length() || (s.length() == dp[i - tbl[d]].length() && s > dp[i - tbl[d]])) {
						dp[i - tbl[d]] = s;
					}
				}
			}
		}
	}
	cout << dp[0] << endl;
	return 0;
}
