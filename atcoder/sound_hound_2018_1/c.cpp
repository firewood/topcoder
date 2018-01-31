// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };

int r, c;

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
	cin >> r >> c;
	vector<string> b(r + 2, string(c + 2, '*'));
	for (int i = 0; i < r; ++i) {
		string s;
		cin >> s;
		b[i + 1] = "*" + s + "*";
	}
	for (int y = 1; y <= r; ++y) {
		for (int x = 1; x <= c; ++x) {
			if (b[y][x] == '.') {
				for (int d = 0; d < 2; ++d) {
					int nx = x + dx[d], ny = y + dy[d];
					if (b[ny][nx] == '.') {
						add_edge(y * c + x, ny * c + nx);
					}
				}
			}
		}
	}
	// max independent set = total - bipartite matching
	int total = 0, matched = 0;
	fill(match, match + 2000, -1);
	for (int y = 1; y <= r; ++y) {
		for (int x = 1; x <= c; ++x) {
			if (b[y][x] == '.') {
				++total;
				int z = y * c + x;
				if (match[z] < 0) {
					fill(used, used + 2000, false);
					matched += dfs(z);
				}
			}
		}
	}
	int ans = total - matched;
	cout << ans << endl;
	return 0;
}
