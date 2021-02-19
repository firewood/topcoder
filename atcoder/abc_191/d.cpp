#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
typedef long double LD;

const LD EPS = 1e-15;

LL solve(long double X, long double Y, long double R) {
#if 1
	LL ans = 0;
	for (LL y = Y - R - 1; y <= Y + R + 1; ++y) {
		LD w = sqrt(max((LD)0.0, R * R - (y - Y) * (y - Y)));
		LL left = X - w - 1, right = X + w + 1;
		for (int i = 0; i < 2; ++i) {
			if (((left - X) * (left - X) + (Y - y) * (Y - y)) > R * R + EPS) {
				++left;
			}
			if (((right - X) * (right - X) + (Y - y) * (Y - y)) > R * R + EPS) {
				--right;
			}
		}
		ans += max(0LL, right - left + 1);
	}
#else
	LL ans = 0, cx = LL(round(X * 10000)), cy = LL(round(Y * 10000)), r = LL(round(R * 10000));
	for (LL y = (cy - r) / 10000 - 1; y <= (cy + r) / 10000; ++y) {
		LL dy = y * 10000 - cy, d = r * r - dy * dy;
		if (d < 0) continue;
		LL w = LL(sqrt(d));
		LL left = (cx - w) / 10000 - 1, right = (cx + w) / 10000 + 1;
		for (int i = 0; i < 2; ++i) {
			LL dx = left * 10000 - cx;
			if (dx * dx + dy * dy > r * r) {
				++left;
			}
			dx = right * 10000 - cx;
			if (dx * dx + dy * dy > r * r) {
				--right;
			}
		}
		ans += max(0LL, right - left + 1);
	}
#endif
	return ans;
}

int main() {
	cout.precision(20);
    long double X, Y, R;
	std::cin >> X >> Y >> R;
	cout << solve(X, Y, R) << endl;
	return 0;
}
