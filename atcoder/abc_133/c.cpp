// C.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL calc(LL a, LL b) {
	LL r = 1LL << 32;
	for (LL i = a; i < b; ++i) {
		for (LL j = a + 1; j <= b; ++j) {
			r = min(r, (i * j) % 2019);
			if (!r) {
				return r;
			}
		}
	}
	return r;
}

int main(int argc, char *argv[]) {
	LL l, r;
	cin >> l >> r;
	LL ans = calc(l, r);
	cout << ans << endl;
	return 0;
}
