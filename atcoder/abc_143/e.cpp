// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	const LL INF = 1LL << 60;
	while (true) {
		int n = -1, m = -1, l = -1, q = -1, a, b, c, s, t;
		cin >> n >> m >> l;
		if (n <= 0) break;
		vector<vector<LL>> d(n, vector<LL>(n, INF)), h(n, vector<LL>(n, INF));
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> c;
			d[a - 1][b - 1] = c;
			d[b - 1][a - 1] = c;
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					if (d[i][j] <= l) {
						h[i][j] = 1;
					}
				}
			}
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					h[i][j] = min(h[i][j], h[i][k] + h[k][j]);
				}
			}
		}
		cin >> q;
		for (int i = 0; i < q; ++i) {
			cin >> s >> t;
			LL dist = h[s - 1][t - 1];
			cout << (dist < INF ? dist - 1 : -1) << endl;
		}
	}
	return 0;
}
