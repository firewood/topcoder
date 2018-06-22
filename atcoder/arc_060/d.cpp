// D.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;
typedef long long LL;

LL check(LL b, LL n) {
	LL c = 0;
	while (n) {
		c += n % b;
		n /= b;
	}
	return c;
}

int main(int argc, char *argv[]) {
	LL n, s;
	cin >> n >> s;
	LL ans = 1LL << 60;
	if (s == 1LL) {
		ans = n;
	}
	for (LL b = 2; b <= 10000; ++b) {
		if (check(b, n) == s) {
			ans = min(ans, b);
		}
	}
	for (LL d = 2; d <= 5; ++d) {
		LL q = (LL)pow(n, 1.0 / d);
		for (LL b = max(2LL, q - 100); b <= q + 100; ++b) {
			if (check(b, n) == s) {
				ans = min(ans, b);
			}
		}
	}
	cout << (ans == (1LL << 60) ? -1 : ans) << endl;
	return 0;
}
