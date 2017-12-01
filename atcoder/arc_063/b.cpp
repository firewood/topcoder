// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int w, h, n;
	cin >> w >> h >> n;
	int c[101][101] = {};
	for (int i = 0; i < n; ++i) {
		int x, y, a, sx, sy, ex, ey;
		cin >> x >> y >> a;
		switch (a) {
		case 1:
			sx = 0, ex = x, sy = 0, ey = h;
			break;
		case 2:
			sx = x, ex = w, sy = 0, ey = h;
			break;
		case 3:
			sx = 0, ex = w, sy = 0, ey = y;
			break;
		case 4:
			sx = 0, ex = w, sy = y, ey = h;
			break;
		}
		for (int i = sy; i < ey; ++i) {
			for (int j = sx; j < ex; ++j) {
				c[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			ans += c[i][j] == 0;
		}
	}
	cout << ans << endl;
	return 0;
}
