// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};

void fill(vector<string> &b, int x, int y) {
	b[y][x] = 'x';
	for (int d = 0; d < 4; ++d) {
		int nx = x + dx[d], ny = y + dy[d];
		if (b[ny][nx] == '.') {
			fill(b, nx, ny);
		}
	}
}

int getmax(vector<string> &b, int x, int y) {
	int r = 0;
	for (int d = 0; d < 4; ++d) {
		int ax = x + dx[d], ay = y + dy[d];
		if (b[ay][ax] == '.') {
			b[ay][ax] = '#';
			for (int d = 0; d < 4; ++d) {
				int bx = ax + dx[d], by = ay + dy[d];
				if (b[by][bx] == '#') {
					b[ay][ax] = 'x';
				}
			}
			vector<string> temp = b;
			int p = 0;
			if (b[ay][ax] == '#') {
				p = 1 + getmax(temp, ax, ay);
			}
			b[ay][ax] = 'x';
			int q = getmax(b, ax, ay);
			if (p > q) {
				b = temp;
				r += p;
			} else {
				b[ay][ax] = 'y';
				r += q;
			}
		}
	}
	return r;
}

int main(int argc, char *argv[]) {
	int r, c;
	cin >> r >> c;
	vector<string> b(r + 2, string(c + 2, '*'));
	for (int i = 0; i < r; ++i) {
		string s;
		cin >> s;
		b[i + 1] = "*" + s + "*";
	}
	int ans = 0;
	for (int i = 1; i <= r; ++i) {
		for (int j = 1; j <= c; ++j) {
			if (b[i][j] == '.') {
				b[i][j] = '#';
				vector<string> temp = b;
				int p = 1 + getmax(temp, i, j);
				b[i][j] = 'x';
				int q = getmax(b, i, j);
				if (p > q) {
					b = temp;
					ans += p;
				} else {
					ans += q;
				}
			}
		}
	}
	for (int i = 0; i < r+2; ++i) {
		cout << b[i] << endl;
	}
	cout << ans << endl;
	return 0;
}
