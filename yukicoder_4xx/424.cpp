#include <iostream>
#include <sstream>

using namespace std;

int b[60][60] = {};
int vis[60][60] = {};
int H, W, sx, sy, gx, gy;

bool dfs(int x, int y) {
	if (x == gx && y == gy) {
		return true;
	}

	vis[x][y] = 1;
	const int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
	for (int d = 0; d < 4; ++d) {
		int nx = x + dx[d], ny = y + dy[d];
		if (!vis[nx][ny] && abs(b[nx][ny] - b[x][y]) <= 1) {
			if (dfs(nx, ny)) {
				return true;
			}
		}
		if (b[nx][ny] < b[x][y]) {
			nx += dx[d], ny += dy[d];
			if (nx >= 0 && ny >= 0 && !vis[nx][ny] && b[nx][ny] == b[x][y]) {
				if (dfs(nx, ny)) {
					return true;
				}
			}
		}
	}
	return false;
}

int main(int argc, char *argv[])
{
	cin >> H >> W >> sx >> sy >> gx >> gy;
	for (int i = 0; i < H; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < W; ++j) {
			b[i + 1][j + 1] = s[j];
		}
	}
	cout << (dfs(sx, sy) ? "YES" : "NO") << endl;
	return 0;
}
