// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char* argv[]) {
	LL k, ans = 0;
	cin >> k;
	for (LL a = 1; a <= k; ++a) {
		for (LL b = 1; b <= k; ++b) {
			LL g = gcd(a, b);
			for (LL c = 1; c <= k; ++c) {
				ans += gcd(g, c);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
