// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> Queue;

int main(int argc, char *argv[])
{
	int R, C, sy, sx, gy, gx;
	cin >> R >> C >> sy >> sx >> gy >> gx;
	--sy, --sx, --gy, --gx;
	vector<string> m(R);
	for (int i = 0; i < R; ++i) {
		cin >> m[i];
	}
	int vis[50][50] = {};
	vis[sy][sx] = 1;
	Queue q;
	q.push_back(II(sy, sx));
	int ans = 0;
	while (q.size() > 0) {
		++ans;
		Queue next;
		for (II &a : q) {
			int dx[] = { -1, 1, 0, 0 };
			int dy[] = { 0, 0, -1, 1 };
			for (int d = 0; d < 4; ++d) {
				int ny = a.first + dy[d], nx = a.second + dx[d];
				if (ny == gy && nx == gx) {
					cout << ans << endl;
					return 0;
				}
				if (ny >= 0 && nx >= 0 && ny < R && nx < C && !vis[ny][nx] && m[ny][nx] != '#') {
					vis[ny][nx] = 1;
					next.push_back(II(ny, nx));
				}
			}
		}
		q = next;
	}
	return 0;
}
