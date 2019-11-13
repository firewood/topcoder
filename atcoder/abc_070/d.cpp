// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

vector<LL> dist;
vector<vector<II>> edges;

void dfs(int n, LL d) {
	if (dist[n] < 0) {
		dist[n] = d;
		for (auto next : edges[n]) {
			dfs(next.first, d + next.second);
		}
	}
}

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, a, b, c, q, k, x, y;
		cin >> n;
		if (n <= 0) return 0;
		edges = vector<vector<II>>(n);
		for (int i = 0; i < n - 1; ++i) {
			cin >> a >> b >> c;
			--a, --b;
			edges[a].push_back({ b, c });
			edges[b].push_back({ a, c });
		}
		dist = vector<LL>(n, -1);
		cin >> q >> k;
		--k;
		dfs(k, 0);
		for (int i = 0; i < q; ++i) {
			cin >> x >> y;
			--x, --y;
			cout << (dist[x] + dist[y]) << endl;
		}
	}
	return 0;
}
