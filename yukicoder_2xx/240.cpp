#include <iostream>
#include <sstream>

using namespace std;

int vis[64][64];

void dfs(int x, int y, int d) {
	vis[y][x] = d;
	if (d >= 4) {
		return;
	}
	for (int i = -2; i <= 2; ++i) {
		for (int j = -2; j <= 2; ++j) {
			if (i * j == 2 || i * j == -2) {
				if (!vis[y + i][x + j]) {
					vis[y + i][x + j] = d + 1;
				}
			}
		}
	}
	for (int i = -2; i <= 2; ++i) {
		for (int j = -2; j <= 2; ++j) {
			if (i * j == 2 || i * j == -2) {
				if (vis[y + i][x + j] == d + 1) {
					dfs(x + j, y + i, d + 1);
				}
			}
		}
	}
}

int main(int argc, char *argv[]) {
	dfs(32, 32, 1);
	int x, y;
	cin >> x >> y;
	x += 32, y += 32;
	string ans = x >= 0 && x < 64 && y >= 0 && y < 64 && vis[y][x] ? "YES" : "NO";
	cout << ans << endl;
	return 0;
}
