#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>

using namespace std;

typedef pair<int, int> II;
typedef pair<int, II> III;
typedef vector<III> IIIVec;

int main(int argc, char *argv[]) {
	int H, W, sx = -1, sy, gx = -1, gy;
	int vis[500][500][2] = {};
	string s[5000];
	cin >> H >> W;
	for (int i = 0; i < H; ++i) {
		cin >> s[i];
		if (sx < 0) {
			sx = s[i].find('S');
			if (sx >= 0) {
				sy = i;
			}
		}
		if (gx < 0) {
			gx = s[i].find('G');
			if (gx >= 0) {
				gy = i;
			}
		}
	}

	IIIVec q;
	q.push_back(III(0, II(sy, sx)));
	vis[sy][sx][0] = 1;
	int ans = -1;
	while (q.size()) {
		++ans;
		IIIVec n;
		for (int i = 0; i != q.size(); ++i) {
			int t = q[i].first;
			int x = q[i].second.second, y = q[i].second.first;
			if (x == gx && y == gy) {
				cout << ans << endl;
				return 0;
			}
			if (t == 0) {
				const int dx[] = { -2,-1,1,2,2,1,-1,-2 };
				const int dy[] = { -1,-2,-2,-1,1,2,2,1 };
				for (int d = 0; d < 8; ++d) {
					int nx = x + dx[d], ny = y + dy[d];
					if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
						int nt = t;
						if (s[ny][nx] == 'R') {
							nt ^= 1;
						}
						if (!vis[ny][nx][nt]) {
							vis[ny][nx][nt] = 1;
							n.push_back(III(nt, II(ny, nx)));
						}
					}
				}
			} else {
				const int dx[] = { -1,1,1,-1 };
				const int dy[] = { -1,-1,1,1 };
				for (int d = 0; d < 4; ++d) {
					int nx = x + dx[d], ny = y + dy[d];
					if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
						int nt = t;
						if (s[ny][nx] == 'R') {
							nt ^= 1;
						}
						if (!vis[ny][nx][nt]) {
							vis[ny][nx][nt] = 1;
							n.push_back(III(nt, II(ny, nx)));
						}
					}
				}
			}
		}
		q = n;
	}
	cout << -1 << endl;
	return 0;
}
