#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL n, ans = 1;
	cin >> n;
	for (LL i = 1; ans && i <= n; ++i) {
		ans = (ans * i) % 1000000000000;
	}
	if (n <= 14) {
		cout << ans << endl;
	} else {
		printf("%012lld\n", ans);
	}
	return 0;
}
