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
	} else if (n < 64) {
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
