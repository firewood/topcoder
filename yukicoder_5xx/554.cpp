#include <iostream>

using namespace std;

static const int MOD = 1000000007;

int main(int argc, char *argv[])
{
	long long n, ans = 1, a[2] = { 0, 1 };
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int p = i % 2, q = !p;
		ans = (i * a[q]) % MOD;
		a[p] = (a[p] + ans) % MOD;
	}
	cout << ans << endl;
	return 0;
}
