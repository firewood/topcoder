// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL calc(LL a, LL b) {
	LL r = 1LL << 32;
	for (LL i = a; i < min(a + 2020, b); ++i) {
		for (LL j = a + 1; j <= min(a + 2022, b); ++j) {
			r = min(r, (i * j) % 2019);
		}
	}
	return r;
}

int main(int argc, char *argv[]) {
	LL l, r;
	cin >> l >> r;
	LL ans = calc(l, r);
	ans = min(ans, calc(max(l, r - 2020), r));
	cout << ans << endl;
	return 0;
}
