// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	while (true) {
		int n = -1;
		cin >> n;
		if (n <= 0) break;
		vector<vector<int>> d(n, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < n; ++j) {
				d[i][j] = s[j] == '1' ? 1 : 1 << 29;
			}
			d[i][i] = 0;
		}
		int ans = 0;
		vector<int> color(n, -1), q(1, 0);
		color[0] = 1;
		while (!q.empty()) {
			vector<int> nx;
			for (int x : q) {
				for (int i = 0; i < n; ++i) {
					if (d[x][i] == 1) {
						if (color[i] < 0) {
							color[i] = !color[x];
							nx.push_back(i);
						} else if (color[i] != !color[x]) {
							ans = -1;
						}
					}
				}
			}
			q = nx;
		}
		if (ans >= 0) {
			for (int k = 0; k < n; ++k) {
				for (int i = 0; i < n; ++i) {
					for (int j = 0; j < n; ++j) {
						d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}
				}
			}
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (d[i][j] < (1 << 29)) {
						ans = max(ans, d[i][j] + 1);
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
