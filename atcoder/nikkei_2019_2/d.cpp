// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		const LL INF = 1LL << 60;
		int n = -1, m, l, r, c;
		LL ans = INF;
		cin >> n >> m;
		if (n < 0) return 0;
		vector<vector<pair<int, LL>>> e(n);
		for (int i = 1; i < n; ++i) {
			e[i].emplace_back(make_pair(i - 1, 0));
		}
		for (int i = 0; i < m; ++i) {
			cin >> l >> r >> c;
			--l, --r;
			e[l].emplace_back(make_pair(r, c));
		}
		priority_queue<pair<int, LL>, vector<pair<int, LL>>, greater<>> q;
		q.emplace(make_pair(0, 0));
		vector<LL> cost(n, INF);
		while (!q.empty()) {
			pair<int, LL> top = q.top();
			q.pop();
			if (cost[top.first] <= top.second) continue;
			if (top.first == n - 1) {
				ans = top.second;
				break;
			}
			cost[top.first] = top.second;
			for (auto kv : e[top.first]) {
				auto c = top.second + kv.second;
				if (cost[kv.first] <= c) continue;
				q.emplace(make_pair(kv.first, c));
			}
		}
		cout << (ans < INF ? ans : -1) << endl;
	}
	return 0;
}
