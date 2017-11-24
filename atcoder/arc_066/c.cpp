// C.

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

static const LL MOD = 1000000007;

int main(int argc, char *argv[])
{
	LL n, a[100000] = {}, ans = 1;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; ++i) {
		if (i % 2) {
			ans = (ans * 2) % MOD;
		}
		if (n % 2) {
			if (a[i] != ((i + 1) / 2) * 2) {
				ans = 0;
			}
		} else {
			if (a[i] != ((i / 2) * 2 + 1)) {
				ans = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
