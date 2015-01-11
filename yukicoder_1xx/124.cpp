#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

struct History {
	int a;
	int b;
	int x;
	int y;
	int dir;
};

typedef pair<int, int> II;
typedef vector<History> Queue;

struct Solver {
	int H;
	int W;
	int b[100][100];
	int vis[4][4][100][100];

public:
	Solver(int h, int w, const int (&bb)[100][100]): H(h), W(w) {
		memcpy(b, bb, sizeof(b));
		memset(vis, 0, sizeof(vis));
	}

	int solve(void) {
		Queue q;
		q.push_back({ -1, b[0][0], 0, 0, 0 });
		int ans = 0;
		while (q.size() > 0) {
			Queue next;
			for (int i = 0; i < (int)q.size(); ++i) {
				const History &h = q[i];
				const int dx[4] = { -1, 0, 1, 0 };
				const int dy[4] = { 0, -1, 0, 1 };
				for (int d = 0; d < 4; ++d) {
					int x = h.x + dx[d], y = h.y + dy[d];
					if (x >= 0 && x < W && y >= 0 && y < H && !(x == 0 && y == 0) && !vis[h.dir][d][y][x]) {
						vis[h.dir][d][y][x] = 1;
						if (h.a < 0 || h.a != b[y][x] && (h.a < h.b && h.b > b[y][x] || h.a > h.b && h.b < b[y][x])) {
							if (x == W - 1 && y == H - 1) {
								return ans + 1;
							}
							next.push_back({ h.b, b[y][x], x, y, d });
						}
					}
				}
			}
			q = next;
			++ans;
		}
		return -1;
	}
};

int main(int argc, char *argv[])
{
	int W, H;
	string s;
	{
		getline(cin, s);
		stringstream ss(s);
		ss >> W >> H;
	}
	int b[100][100] = {};
	for (int i = 0; i < H; ++i) {
		getline(cin, s);
		stringstream ss(s);
		for (int j = 0; j < W; ++j) {
			ss >> b[i][j];
		}
	}
	Solver solver(H, W, b);
	int ans = solver.solve();
	cout << ans << endl;
	return 0;
}
