// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

static const LL INF = 1LL << 60;

struct Edge {
	int from;
	int to;
	int cost;
};

int main(int argc, char* argv[]) {
	int n, m, p;
	cin >> n >> m >> p;
	vector<Edge> edges;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ a - 1, b - 1, -(c - p) });
	}
	// Bellman-Ford
	vector<LL> costs(n, INF);
	costs[0] = 0;
	LL ans = 0;
	for (int i = 0; i < m * 2; ++i) {
		for (int j = 0; j < m; ++j) {
			if (costs[edges[j].from] < INF) {
				LL cost = costs[edges[j].from] + edges[j].cost;
				if (cost < costs[edges[j].to]) {
					costs[edges[j].to] = cost;
					if (edges[j].to == n - 1) {
						ans = max(0LL, -cost);
						if (i >= m) {
							ans = -1;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
