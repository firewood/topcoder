// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL a, b, c, x, y;

LL cost(LL ab) {
	LL t = ab * 2 * c;
	t += max(0LL, x - ab) * a;
	t += max(0LL, y - ab) * b;
	return t;
}

int main(int argc, char *argv[]) {
	cin >> a >> b >> c >> x >> y;
	LL left = 0, right = max(x, y);
	for (int t = 0; t < 100; ++t) {
		if (cost((left * 2 + right) / 3) < cost((left + right * 2) / 3)) {
			right = (left + right * 2) / 3;
		} else {
			left = (left * 2 + right) / 3;
		}
	}
	LL ans = 1LL << 60;
	for (LL ab = max(0LL, left - 5); ab <= left + 5; ++ab) {
		ans = min(ans, cost(ab));
	}
	cout << ans << endl;
	return 0;
}
