// B.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> h;
vector<vector<int> > e;
vector<int> vis;

int dfs(int node) {
	if (vis[node]) {
		return 0;
	}
	vis[node] = 1;
	int r = 0;
	for (int next : e[node]) {
		r += dfs(next);
	}
	return r ? r + 2 : h[node] * 2;
}

int main(int argc, char *argv[]) {
	int n, x;
	cin >> n >> x;
	h.resize(n);
	e.resize(n);
	vis.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		e[a - 1].push_back(b - 1);
		e[b - 1].push_back(a - 1);
	}
	h[x - 1] = 0;
	int ans = max(0, dfs(x - 1) - 2);
	cout << ans << endl;
}
