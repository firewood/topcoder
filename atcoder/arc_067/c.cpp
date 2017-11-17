// C.

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

static const LL MOD = 1000000007;

int main(int argc, char *argv[])
{
	LL n, ans = 1;
	cin >> n;
	int f[1001] = {};
	for (int i = 2; i <= n; ++i) {
		if (!f[i]) {
			LL c = 0;
			for (int j = i; j <= n; j += i) {
				f[j] = 1;
				int k = j;
				while ((k % i) == 0) {
					k /= i;
					++c;
				}
			}
			ans = (ans * (c + 1)) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
