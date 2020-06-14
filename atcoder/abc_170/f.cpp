// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> II;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int h = -1, w, k, sx, sy, gx, gy, ans = -1;
		cin >> h >> w >> k >> sy >> sx >> gy >> gx;
		--sx, --sy, --gx, --gy;
		if (h < 0) return 0;
		vector<string> b(h);
		for (int i = 0; i < h; ++i) {
			cin >> b[i];
		}
		queue<II> q;
		vector<vector<int>> dist(h, vector<int>(w, 1 << 30));
		q.push(II(sy, sx));
		dist[sy][sx] = 0;
		while (!q.empty()) {
			int y = q.front().first, x = q.front().second;
			q.pop();
			if (x == gx && y == gy) {
				ans = dist[y][x];
				break;
			}
			int cost = dist[y][x] + 1;
			const int dx[4] = { -1,1,0,0 };
			const int dy[4] = { 0,0,-1,1 };
			for (int dir = 0; dir < 4; ++dir) {
				for (int d = 1; d <= k; ++d) {
					int nx = x + dx[dir] * d, ny = y + dy[dir] * d;
					if (nx < 0 || nx >= w || ny < 0 || ny >= h) break;
					if (b[ny][nx] != '.') break;
					if (cost > dist[ny][nx]) break;
					if (cost < dist[ny][nx]) {
						dist[ny][nx] = cost;
						q.push(II(ny, nx));
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
