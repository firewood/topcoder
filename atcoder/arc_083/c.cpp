// C.

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c, d, e, f, t = 0, s = 0;
	cin >> a >> b >> c >> d >> e >> f;
	for (int i = 0; i <= 30; i += a) {
		for (int j = 0; i + j <= 30; j += b) {
			int k = i + j;
			int r = min(e * k, f - k * 100);
			if (r > 0) {
				int x = 0;
				for (int l = 0; l <= r; l += c) {
					for (int m = 0; l + m <= r; m += d) {
						x = max(x, l + m);
					}
				}
				if (t == 0 || x * t > s * k) {
					t = k;
					s = x;
				}
			}
		}
	}
	cout << (t * 100 + s) << " " << s << endl;
	return 0;
}
