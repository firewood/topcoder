// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> II;

// From The Programming Contest Challendge Book
vector<int> G[2000];
int match[2000];
bool used[2000];

void add_edge(int u, int v) {
	G[u].push_back(v);
	G[v].push_back(u);
}

bool dfs(int v) {
	used[v] = true;
	int i;
	for (i = 0; i < (int)G[v].size(); ++i) {
		int u = G[v][i];
		int w = match[u];
		if (w < 0 || !used[w] && dfs(w)) {
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	int n;
	vector<II> red, blue;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		red.push_back(II(a, b));
	}
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		blue.push_back(II(a, b));
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (red[i].first < blue[j].first && red[i].second < blue[j].second) {
				add_edge(i, j + n);
			}
		}
	}

	fill(match, match + 2 * n, -1);
	int ans = 0;
	for (int v = 0; v < n; ++v) {
		if (match[v] < 0) {
			fill(used, used + 2 * n, false);
			if (dfs(v)) {
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
