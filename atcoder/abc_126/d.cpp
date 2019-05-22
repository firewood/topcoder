// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<int> > edges;
vector< vector<int> > length;
vector<int> color;

void dfs(int n, int f) {
	if (color[n] < 0) {
		color[n] = f;
		for (int i = 0; i < (int)edges[n].size(); ++i) {
			dfs(edges[n][i], (f + length[n][i]) % 2);
		}
	}
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	edges.resize(n);
	length.resize(n);
	color = vector<int>(n, -1);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		edges[u].push_back(v);
		edges[v].push_back(u);
		length[u].push_back(w);
		length[v].push_back(w);
	}
	dfs(0, 0);
	for (int i = 0; i < n; ++i) {
		cout << color[i] << endl;
	}
	return 0;
}
