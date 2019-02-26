// C.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[]) {
	int n, a, b, c, ans = 1 << 30;
	cin >> n >> a >> b >> c;
	vector<int> l(n);
	for (int i = 0; i < n; ++i) {
		cin >> l[i];
	}
	int bm = 1 << n;
	for (int i = 1; i < bm; ++i) {
		int acost = 0, alen = 0;
		for (int x = 0; x < n; ++x) {
			if (i & (1 << x)) {
				if (alen > 0) {
					acost += 10;
				}
				alen += l[x];
			}
		}
		acost += abs(a - alen);
		for (int j = 1; j < bm; ++j) {
			if (i & j) continue;
			int blen = 0, bcost = acost;
			for (int x = 0; x < n; ++x) {
				if (j & (1 << x)) {
					if (blen > 0) {
						bcost += 10;
					}
					blen += l[x];
				}
			}
			bcost += abs(b - blen);
			for (int k = 1; k < bm; ++k) {
				if ((i & k) != 0 || (j & k) != 0) continue;
				int clen = 0, ccost = bcost;
				for (int x = 0; x < n; ++x) {
					if (k & (1 << x)) {
						if (clen > 0) {
							ccost += 10;
						}
						clen += l[x];
					}
				}
				ccost += abs(c - clen);
				ans = min(ans, ccost);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
