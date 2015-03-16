#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

int W, H;
int d[100][100];
int vis[100][100];
int sx, sy;

bool dfs(int x, int y, int prevx, int prevy) {
	vis[y][x] = 1;
	if (x == sx && y == sy) {
		return true;
	}
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };
	for (int dir = 0; dir < 4; ++dir) {
		int nx = x + dx[dir], ny = y + dy[dir];
		if (nx >= 0 && nx < W && ny >= 0 && ny < H && !vis[ny][nx] && d[y][x] == d[ny][nx] && (nx != prevx || ny != prevy)) {
			if (dfs(nx, ny, x, y)) {
				return true;
			}
		}
	}
	return false;
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	stringstream ss(s);
	ss >> W >> H;
	for (int i = 0; i < H; ++i) {
		getline(cin, s);
		stringstream ss(s);
		for (int j = 0; j < W; ++j) {
			ss >> d[i][j];
		}
	}

	bool possible = false;
	for (int i = 0; i < H; ++i) {
		for (int j = 1; !possible && j < W; ++j) {
			if (d[i][j - 1] == d[i][j]) {
				memset(vis, 0, sizeof(vis));
				sx = j - 1, sy = i;
				if (dfs(j, i, j - 1, i)) {
					possible = true;
				}
			}
		}
	}

	cout << (possible ? "possible" : "impossible") << endl;
	return 0;
}
