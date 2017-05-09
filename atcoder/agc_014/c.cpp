// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> II;

void update_r(int h, int w, int x, int y, int &r) {
	r = min(r, x);
	r = min(r, y);
	r = min(r, w - 1 - x);
	r = min(r, h - 1 - y);
}

int main(int argc, char *argv[])
{
	int h, w, k, sx, sy, r = 1 << 30;
	cin >> h >> w >> k;
	string b[1000];
	for (int i = 0; i < h; ++i) {
		cin >> b[i];
		int pos = b[i].find('S');
		if (pos >= 0) {
			sx = pos, sy = i;
		}
	}
	update_r(h, w, sx, sy, r);
	vector<II> v;
	v.push_back(II(sx, sy));
	for (int i = 0; i < k; ++i) {
		vector<II> next;
		for (auto &xy : v) {
			int dx[] = {-1,1,0,0};
			int dy[] = {0,0,-1,1};
			for (int d = 0; d < 4; ++d) {
				int x = xy.first + dx[d], y = xy.second + dy[d];
				if (x >= 0 && x < w && y >= 0 && y < h && b[y][x] == '.') {
					b[y][x] = '?';
					next.push_back(II(x, y));
					update_r(h, w, x, y, r);
				}
			}
		}
		v = next;
	}
	int ans = 1 + (r + k - 1) / k;
	cout << ans << endl;
	return 0;
}
