// C.

#include <iostream>
#include <algorithm>
#include <set>
#include <cstring>

using namespace std;

int sum[2];
set<int> g[100000];
int color[100000];

bool dfs(int node, int c) {
	color[node] = c;
	++sum[c >= 0];
	for (int next : g[node]) {
		if (color[next] == -c) {
			;
		} else if (color[next] == c) {
			return false;
		} else if (!dfs(next, -c)) {
			return false;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].insert(b);
		g[b].insert(a);
	}
	int ans = 0;
	if (dfs(0, 1)) {
		ans = sum[0] * sum[1] - m;
	} else {
		ans = (n * (n - 1)) / 2 - m;
	}
	cout << ans << endl;
	return 0;
}
