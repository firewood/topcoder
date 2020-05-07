// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int main(int argc, char* argv[]) {
	while (true) {
		int n = -1, m = -1, a, b, c;
		cin >> n >> m;
		if (n <= 0 || m <= 0) break;
		vector<tuple<int, int, int>> edges;
		vector<vector<int>> dist(n, vector<int>(n, 1 << 29));
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> c;
			--a, --b;
			edges.emplace_back(make_tuple(a, b, c));
			dist[a][b] = c;
			dist[b][a] = c;
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			int a = get<0>(edges[i]), b = get<1>(edges[i]), c = get<2>(edges[i]);
			ans += dist[a][b] < c;
		}
		cout << ans << endl;
	}
	return 0;
}
