#include <iostream>
#include <cmath>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL x;
	cin >> x;
	LL r = sqrt(x);
	LL ans = 1;
	for (LL i = 2; i <= r; ++i) {
		LL cnt = 0;
		while ((x % i) == 0) {
			x /= i;
			++cnt;
		}
		if (cnt % 2) {
			ans *= i;
		}
	}
	if (x > 1) {
		ans *= x;
	}
	cout << ans << endl;
	return 0;
}
