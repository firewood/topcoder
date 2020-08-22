// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

static const int dx[4] = { -1,1,0,0 };
static const int dy[4] = { 0,0,-1,1 };

int h;
int w;

void dfs(int y, int x, int g, vector<string> &b, vector<vector<int>>& vis) {
	vis[y][x] = g;
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir], nx = x + dx[dir];
		if (ny >= 0 && ny < h && nx >= 0 && nx < w) {
			if (b[ny][nx] != '#' && vis[ny][nx] < 0) {
				dfs(ny, nx, g, b, vis);
			}
		}
	}
}

int main(int argc, char* argv[]) {
	int sh, sw, eh, ew, ans;
	cin >> h >> w >> sh >> sw >> eh >> ew;
	--sh, --sw, --eh, --ew;
	vector<string> b(h);
	for (int i = 0; i < h; ++i) {
		cin >> b[i];
	}
	vector<vector<int>> vis(h, vector<int>(w, -1));
	int g = 0;
	for (int r = 0; r < h; ++r) {
		for (int c = 0; c < w; ++c) {
			if (b[r][c] != '#' && vis[r][c] < 0) {
				dfs(r, c, g++, b, vis);
			}
		}
	}
	vector<set<int>> e(g);
	for (int r = 0; r < h; ++r) {
		for (int c = 0; c < w; ++c) {
			if (b[r][c] != '#') {
				for (int dy = -2; dy <= 2; ++dy) {
					for (int dx = -2; dx <= 2; ++dx) {
						int y = r + dy, x = c + dx;
						if (y >= 0 && y < h && x >= 0 && x < w) {
							if (vis[y][x] >= 0 && vis[r][c] != vis[y][x]) {
								e[vis[r][c]].emplace(vis[y][x]);
								e[vis[y][x]].emplace(vis[r][c]);
							}
						}
					}
				}
			}
		}
	}
	vector<int> q;
	vector<int> vg(g);
	q.emplace_back(vis[sh][sw]);
	vg[vis[sh][sw]] = 1;
	for (ans = 0; !q.empty(); ++ans) {
		vector<int> nq;
		for (int next : q) {
			if (next == vis[eh][ew]) {
				cout << ans << endl;
				return 0;
			}
			for (int a : e[next]) {
				if (vg[a] == 0) {
					vg[a] = 1;
					nq.emplace_back(a);
				}
			}
		}
		q = nq;
	}
	cout << -1 << endl;
	return 0;
}
