// B. 

#include <sstream>
#include <iostream>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[])
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; ++tt) {
		LL a, b, c, d;
		cin >> a >> b >> c >> d;
		bool ans = a >= b && b <= d;
		if (ans && b > c) {
			LL r = a % b;
			LL p = d % b;
			if (p) {
				LL g = gcd(p, b);
				r = b + r - (r / g + 1) * g;
			}
			ans = r <= c;
		}
		cout << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}
