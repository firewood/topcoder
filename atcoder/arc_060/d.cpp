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
	if (s == n) {
		ans = n + 1;
	}
	LL m = sqrt(n);
	for (LL b = 2; b <= m; ++b) {
		if (check(b, n) == s) {
			ans = min(ans, b);
		}
	}
	for (LL p = 1; p < m; ++p) {
		LL b = (n - s) / p + 1;
		LL q = s - p;
		if (b >= m && q >= 0 && q < b && n == (p * b + q)) {
			ans = min(ans, b);
		}
	}
	cout << (ans == (1LL << 60) ? -1 : ans) << endl;
	return 0;
}
