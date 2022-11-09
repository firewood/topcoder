#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> II;

const int dy[4] = { -1,1,0,0 };
const int dx[4] = { 0,0,-1,1 };

bool solve(int H, int W, std::vector<std::string>& b, int sy, int sx, int ey, int ex) {
	vector<vector<int>> vis(H, vector<int>(W));
	vis[sy][sx] = 1;
	vector<II> q;
	q.emplace_back(II(sy, sx));
	for (int t = 1; !q.empty(); ++t) {
		vector<II> nq;
		for (auto kv : q) {
			int i = kv.first, j = kv.second;
			for (int dir = 0; dir < 4; ++dir) {
				int ny = i + dy[dir], nx = j + dx[dir];
				if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
					if (b[ny][nx] == '#')continue;
					if (vis[ny][nx]) continue;
					if (ny == ey && nx == ex) {
						if (t < 3) continue;
						return true;
					}
					vis[ny][nx] = 1;
					nq.emplace_back(II(ny, nx));
				}
			}
		}
		q = nq;
	}
	return false;
}

bool solve(int H, int W, std::vector<std::string>& b) {
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (b[i][j] == 'S') {
				for (int dir = 0; dir < 4; ++dir) {
					int ny = i + dy[dir], nx = j + dx[dir];
					if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
						if (b[ny][nx] != '#') {
							b[ny][nx] = '#';
							if (solve(H, W, b, ny, nx, i, j)) {
								return true;
							}
							b[ny][nx] = '.';
						}
					}
				}
			}
		}
	}
	return false;
}

int main() {
	int H, W;
	std::cin >> H >> W;
	std::vector<std::string> a(H);
	for (int i = 0; i < H; i++) {
		std::cin >> a[i];
	}
	cout << (solve(H, W, a) ? "Yes" : "No") << endl;
	return 0;
}
