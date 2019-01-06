// D.

#include <sstream>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long LL;

static const LL MOD = 998244353;

int main(int argc, char *argv[])
{
	LL n;
	cin >> n;
	LL ans = 0;
	LL f = 1;
	for (LL i = 1; i <= n; ++i) {
		f = (f * i) % MOD;
	}
	ans += f;
	LL x = 1;
	for (LL i = n; i >= 2; --i) {
		x = (x * i) % MOD;
		LL r = (f - x + MOD) % MOD;
		ans = (ans + r) % MOD;
	}
	cout << ans << endl;
	return 0;
}
