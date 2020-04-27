// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> II;
typedef pair<LL, II> LII;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		const LL MAX = 1LL << 60;
		const int MAX_SILVER = 2500;
		int n = -1, m, s;
		cin >> n >> m >> s;
		if (n < 0) return 0;
		vector<vector<int>> edge(n);
		vector<vector<int>> fare(n);
		vector<vector<int>> dist(n);
		vector<int> rate(n);
		vector<int> time(n);
		vector<vector<LL>> mincost(n, vector<LL>(MAX_SILVER + 1, MAX));
		for (int i = 0; i < m; ++i) {
			int u, v, a, b;
			cin >> u >> v >> a >> b;
			--u, --v;
			edge[u].push_back(v);
			edge[v].push_back(u);
			fare[u].push_back(a);
			fare[v].push_back(a);
			dist[u].push_back(b);
			dist[v].push_back(b);
		}
		for (int i = 0; i < n; ++i) {
			cin >> rate[i] >> time[i];
		}
		priority_queue<LII, vector<LII>, greater<>> q;
		auto push = [&](int pos, int silver, LL cost) {
			for (; ; silver += rate[pos], cost += time[pos]) {
				silver = min(silver, MAX_SILVER);
				if (cost < mincost[pos][silver]) {
					mincost[pos][silver] = cost;
					q.emplace(make_pair(cost, make_pair(silver, pos)));
				}
				if (silver >= MAX_SILVER) break;
			}
		};
		vector<LL> ans(n, MAX);
		push(0, s, 0);
		while (!q.empty()) {
			LII top = q.top();
			q.pop();
			LL cost = top.first;
			int silver = top.second.first;
			int pos = top.second.second;
			if (cost > mincost[pos][silver]) continue;
			ans[pos] = min(ans[pos], cost);
			for (size_t i = 0; i < edge[pos].size(); ++i) {
				if (silver >= fare[pos][i]) {
					push(edge[pos][i], silver - fare[pos][i], cost + dist[pos][i]);
				}
			}
		}
		for (int i = 1; i < n; ++i) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}
