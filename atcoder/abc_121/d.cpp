// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

static LL f(LL x) {
#if 1
	LL r = 0;
	for (LL i = max(0LL, ((x - 4) | 3) + 1); i <= x; ++i) {
		r ^= i;
	}
	return r;
#else
	switch (x & 3) {
	case 0:
		return x;
	case 1:
		return 1;
	case 2:
		return x | 1;
	default:
		return 0;
	}
#endif
}

int main(int argc, char *argv[]) {
	LL a, b;
	cin >> a >> b;
	LL ans = f(b) ^ f(a - 1);
	cout << ans << endl;
	return 0;
}
