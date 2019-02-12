// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL k, a, b;
	cin >> k >> a >> b;
	LL ans = 1 + k;
	if (b > a) {
		LL r = k - (a - 1);
		if (r >= 0) {
			LL x = a + (b - a) * (r / 2) + (r % 2);
			ans = max(ans, x);
		}
	}
	cout << ans << endl;
	return 0;
}
