// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
static const LL MOD = 1000000007;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	static LL sum[100001], single[100001];
	for (int i = 1; i <= n; ++i) {
		LL x = 1;
		for (int j = 0; j < 10; ++j) {
			x = (x * i) % MOD;
		}
		sum[i] = x;
		single[i] = (MOD + sum[i] - sum[i - 1]) % MOD;
	}
	LL ans = 0;
	for (int i = 1; i <= n; ++i) {
		int r = n / i;
		LL b = (single[i] * sum[r]) % MOD;
		ans = (ans + b) % MOD;
	}
	cout << ans << endl;
	return 0;
}
