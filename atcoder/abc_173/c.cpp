// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	int h, w, k, ans = 0;
	cin >> h >> w >> k;
	vector<string> b(h);
	for (int i = 0; i < h; ++i) {
		cin >> b[i];
	}
	for (int yf = 0; yf < 1 << h; ++yf) {
		for (int xf = 0; xf < 1 << w; ++xf) {
			int cnt = 0;
			for (int y = 0; y < h; ++y) {
				if (yf & (1 << y)) continue;
				for (int x = 0; x < w; ++x) {
					if (xf & (1 << x)) continue;
					cnt += b[y][x] == '#';
				}
			}
			ans += cnt == k;
		}
	}
	cout << ans << endl;
	return 0;
}
