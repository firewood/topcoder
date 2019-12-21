// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int h, w;
vector<string> b;
vector<string> r;
vector<string> f;

void restore(int y, int x) {
	if (b[y][x] == '.') return;
	for (int dy = -1; dy <= 1; ++dy) {
		for (int dx = -1; dx <= 1; ++dx) {
			if (y + dy >= 0 && y + dy < h && x + dx >= 0 && x + dx < w) {
				if (b[y + dy][x + dx] == '.') return;
			}
		}
	}
	r[y][x] = '#';
}

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		h = -1;
		cin >> h >> w;
		if (h < 0) return 0;
		b.resize(h);
		r = vector<string>(h, string(w, '.'));
		for (int i = 0; i < h; ++i) {
			cin >> b[i];
		}
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				restore(y, x);
			}
		}
		f = r;
		for (int y = 0; y < h; ++y) {
			for (int x = 0; x < w; ++x) {
				if (r[y][x] == '.') continue;
				for (int dy = -1; dy <= 1; ++dy) {
					for (int dx = -1; dx <= 1; ++dx) {
						if (y + dy >= 0 && y + dy < h && x + dx >= 0 && x + dx < w) {
							f[y + dy][x + dx] = '#';
						}
					}
				}
			}
		}
		if (b == f) {
			cout << "possible" << endl;
			for (int i = 0; i < h; ++i) {
				cout << r[i] << endl;
			}
		} else {
			cout << "impossible" << endl;
		}
	}
	return 0;
}
