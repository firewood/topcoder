// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	LL n, k;
	cin >> n >> k;
	LL ans = n;
	if (ans > 0) {
		if (k * 10 < n) {
			LL c = max(0LL, (n - k) / k - 2);
			n -= c * k;
		}
		for (int i = 0; i < 100; ++i) {
			n = abs(n - k);
			ans = min(ans, n);
		}
	}
	cout << ans << endl;
	return 0;
}
