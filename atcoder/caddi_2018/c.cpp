// C.

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, p, ans = 1;
	cin >> n >> p;
	if (n == 1) {
		ans = p;
	} else if (n >= 64) {
		;
	} else if (n >= 4) {
		LL sq = (LL)sqrt(p);
		LL m = (LL)sqrt(sq);
		for (LL a = m; a > 1; --a) {
			LL x = 1;
			for (LL b = 0; b < n; ++b) {
				x *= a;
				if (x > p) {
					break;
				}
			}
			if (p >= x && (p % x) == 0) {
				ans = a;
				break;
			}
		}
	} else {
		LL sq = (LL)sqrt(p);
		for (LL a = sq; a > 1; --a) {
			LL x = 1;
			for (LL b = 0; b < n; ++b) {
				x *= a;
				if (x > p) {
					break;
				}
			}
			if (p >= x && (p % x) == 0) {
				ans = a;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
