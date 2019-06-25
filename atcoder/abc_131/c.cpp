// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

LL count(LL x, LL y) {
	return x / y;
}

LL count(LL x, LL y, LL z) {
	return count(y, z) - count(x - 1, z);
}

int main(int argc, char *argv[]) {
	LL a, b, c, d;
	cin >> a >> b >> c >> d;
	LL ans = b - a + 1 - count(a, b, c) - count(a, b, d) + count(a, b, lcm(c, d));
	cout << ans << endl;
	return 0;
}
