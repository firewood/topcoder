#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

const int dy[4] = { 0, -1, 0, 1 };
const int dx[4] = { -1, 0, 1, 0 };

int H, W;
vector<string> B;
vector<vector<int>> vis;

void dfs(int y, int x, int z) {
	vis[y][x] = z;
	for (int dir = 0; dir < 4; ++dir) {
		int ny = y + dy[dir], nx = x + dx[dir];
		if (ny >= 0 && ny < H && nx >= 0 && nx < W && !vis[ny][nx] && B[ny][nx] != '#') {
			vis[ny][nx] = z;
			dfs(ny, nx, z);
		}
	}
}

int main() {
	cin >> H >> W;
	B.resize(H);
	vis = vector<vector<int>>(H, vector<int>(W));
	for (int i = 0; i < H; ++i) {
		cin >> B[i];
	}
	int g = 0;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (B[i][j] != '#' && !vis[i][j]) {
				dfs(i, j, ++g);
			}
		}
	}
	int ans = 0;
	for (int y = 0; y < H; ++y) {
		for (int x = 0; x < W; ++x) {
			if (B[y][x] != '#') continue;
			set<int> s;
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir], nx = x + dx[dir];
				if (ny >= 0 && ny < H && nx >= 0 && nx < W && B[ny][nx] != '#') {
					s.insert(vis[ny][nx]);
				}
			}
	
			ans += s.size() == g;
		}
	}
	cout << ans << endl;
	return 0;
}
