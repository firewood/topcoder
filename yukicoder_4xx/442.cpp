#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[]) {
	LL a, b;
	cin >> a >> b;
	LL ab = a + b, ga = gcd(a, ab), gb = gcd(b, ab), g = gcd(ga, gb);
	LL ans = g * gcd(ab / g, (ga / g) * gb);
	cout << ans << endl;
	return 0;
}
