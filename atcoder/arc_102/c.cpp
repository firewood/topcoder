// C.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, k, ans = 0;
	cin >> n >> k;
	for (LL i = 1; i <= n; ++i) {
		if ((i * 2) % k == 0) {
			LL a = n - (i % k);
			LL b = a / k + (a % k ? 0 : 1);
			ans += b * b;
		}
	}
	cout << ans << endl;
	return 0;
}
