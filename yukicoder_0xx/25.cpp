#include <iostream>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[]) {
	LL N, M;
	cin >> N >> M;
	LL g = gcd(N, M);
	LL a = N / g, b = M / g;
	for (LL d = 2; d <= 5; d += 3) {
		while ((b % d) == 0) {
			b /= d;
			if ((a % d) == 0) {
				a /= d;
			} else {
				a = ((a % 10) * 10) / d;
			}
		}
	}
	while ((a % 10) == 0) {
		a /= 10;
	}
	LL ans = b == 1 ? (a % 10) : -1;
	cout << ans << endl;
	return 0;
}
