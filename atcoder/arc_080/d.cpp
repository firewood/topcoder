// D.

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	int h, w, n, a, col[100][100], x = 0, y = 0, d = 1;
	cin >> h >> w >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		for (int j = 0; j < a; ++j) {
			if (x < 0) {
				x = 0;
				++y;
				d = 1;
			} else if (x >= w) {
				x = w - 1;
				++y;
				d = -1;
			}
			col[y][x] = i + 1;
			x += d;
		}
	}
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (j) {
				cout << " ";
			}
			cout << col[i][j];
		}
		cout << endl;
	}
	return 0;
}
