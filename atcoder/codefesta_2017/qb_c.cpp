// C.

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

int ans;
set<int> gs[100000];
vector<int> gv[100000];
int vis[100000][2];

void dfs(int p, int current, int f) {
	if (f && p != current && gs[p].find(current) == gs[p].end()) {
		++ans;
		gs[p].insert(current);
		gs[current].insert(p);
		gv[p].push_back(current);
		gv[current].push_back(p);
	}
	vis[current][f] = 1;
	f ^= 1;
	int sz = (int)gv[current].size();
	for (int i = 0; i < sz; ++i) {
		int next = gv[current][i];
		if (!vis[next][f]) {
			dfs(p, next, f);
		}
	}
}

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		gs[a].insert(b);
		gs[b].insert(a);
		gv[a].push_back(b);
		gv[b].push_back(a);
	}
	for (int i = 0; i < n; ++i) {
		memset(vis, 0, sizeof(vis));
		vis[i][0] = 1;
		int sz = (int)gv[i].size();
		for (int j = 0; j < sz; ++j) {
			int n = gv[i][j];
			if (!vis[n][1]) {
				dfs(i, n, 1);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
