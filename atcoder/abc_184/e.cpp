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

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { -1, 0, 1, 0 };

int solve(long long H, long long W, std::vector<std::string>& b) {
	vector<vector<II>> w(26);
	int sy = -1, sx = -1, ey = -1, ex = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; ++j) {
			int c = b[i][j] - 'a';
			if (c >= 0 && c < 26) {
				w[c].emplace_back(II(i, j));
			}
			if (b[i][j] == 'S') {
				sy = i, sx = j;
			}
			if (b[i][j] == 'G') {
				ey = i, ex = j;
			}
		}
	}
	vector<vector<int>> visited(H, vector<int>(W));
	vector<II> q;
	q.emplace_back(II(sy, sx));
	int cnt = 0;
	while (!q.empty()) {
		vector<II> nq;
		for (auto kv : q) {
			int y = kv.first, x = kv.second;
			if (y == ey && x == ex) return cnt;
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir], nx = x + dx[dir];
				if (ny >= 0 && ny < H && nx >= 0 && nx < W && b[ny][nx] != '#' && !visited[ny][nx]) {
					visited[ny][nx] = 1;
					nq.emplace_back(II(ny, nx));
				}
			}
			int c = b[y][x] - 'a';
			if (c >= 0 && c < 26) {
				for (auto kv : w[c]) {
					int y = kv.first, x = kv.second;
					if (!visited[y][x]) {
						visited[y][x] = 1;
						nq.emplace_back(kv);
					}
				}
				w[c].clear();
			}
		}
		++cnt;
		q = nq;
	}
	return -1;
}

int main() {
	long long H, W;
	std::cin >> H >> W;
	std::vector<std::string> a(H);
	for (int i = 0; i < H; i++) {
		std::cin >> a[i];
	}
	int ans = solve(H, W, a);
	cout << ans << endl;
	return 0;
}
