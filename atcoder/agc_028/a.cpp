// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

int main(int argc, char *argv[]) {
	LL n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	LL g = gcd(n, m);
	bool ok = true;
	for (LL i = 0; i < g; ++i) {
		if (s[(s.length() / g) * i] != t[(t.length() / g) * i]) {
			ok = false;
		}
	}
	LL len = lcm(n, m);
	cout << (ok ? len : -1) << endl;
	return 0;
}
