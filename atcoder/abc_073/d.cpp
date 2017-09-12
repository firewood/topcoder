// D.

#include <iostream>
#include <algorithm>
#include <numeric>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int n, m, r, a, b, c, d[200][200];
	cin >> n >> m >> r;
	int vis[8];
	for (int i = 0; i < r; ++i) {
		cin >> vis[i];
		--vis[i];
	}
	sort(vis, vis + r);
	memset(d, 0x3f, sizeof(d));
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		d[a-1][b-1] = d[b-1][a-1] = c;
	}
	for (int k = 0; k < n; ++k) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ans = 1<<30;
	do {
		int cost = 0;
		for (int i = 1; i < r; ++i) {
			cost += d[vis[i-1]][vis[i]];
		}
		ans = min(ans, cost);
	} while (next_permutation(vis, vis + r));
	cout << ans << endl;
	return 0;
}
