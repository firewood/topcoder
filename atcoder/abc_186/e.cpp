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

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

LL extgcd(LL a, LL b, LL& x, LL& y) {
	LL d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1, y = 0;
	}
	return d;
}

int main() {
	LL t, n, s, k, ans;
	cin >> t;
	for (LL tt = 0; tt < t; ++tt) {
		ans = -1;
		cin >> n >> s >> k;
		LL a = gcd(n, k), b = gcd(a, s);
		if (b < a) {
			;
		} else {
			LL x = 0, y = 0;
			LL g = extgcd(k, n, x, y);
			ans = (((x + n) * (n - s)) % n) / g;

		}
		cout << ans << endl;
	}
	return 0;
}
