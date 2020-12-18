#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
static const LL INF = 1LL << 60;

int main() {
	LL n, m, a, b, c, warp_costs[3][3];
	string s;
	cin >> n >> m >> warp_costs[0][1] >> warp_costs[0][2] >> warp_costs[1][2];
	cin >> s;
	vector<vector<II>> edges(n);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		--a, --b;
		edges[a].emplace_back(II(b, c));
		edges[b].emplace_back(II(a, c));
	}
	vector<vector<LL>> type_nodes(3);
	for (int i = 0; i < n; ++i) {
		type_nodes[s[i] - 'A'].emplace_back(i);
	}
	priority_queue<II, vector<II>, greater<>> q;
	q.emplace(II(0, 0));
	vector<LL> costs(n, 1LL << 60);
	costs[0] = 0;
	bool warp_used[3] = {};
	while (!q.empty()) {
		II top = q.top();
		q.pop();
		LL cost = top.first;
		LL node = top.second;
		LL type = s[node] - 'A';
		if (cost > costs[node]) continue;
		for (auto kv : edges[node]) {
			LL next_node = kv.first;
			LL next_cost = cost + kv.second;
			if (next_cost >= costs[next_node]) continue;
			costs[next_node] = next_cost;
			q.emplace(II(next_cost, next_node));
		}
		if (!warp_used[type]) {
			warp_used[type] = true;
			for (LL next_type = 0; next_type < 3; ++next_type) {
				if (type == next_type) continue;
				LL next_cost = cost + warp_costs[min(type, next_type)][max(type, next_type)];
				for (auto next_node : type_nodes[next_type]) {
					if (next_cost >= costs[next_node]) continue;
					costs[next_node] = next_cost;
					q.emplace(II(next_cost, next_node));
				}
			}
		}
	}
	cout << costs[n - 1] << endl;
	return 0;
}
