// C.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, k, ans = 0;
	cin >> n >> k;
	for (LL a = 1; a <= n; ++a) {
		if ((a * 2) % k == 0) {
			LL b = k - (a % k);
			LL c = (n - b + k) / k;
			ans += c * c;
		}
	}
	cout << ans << endl;
	return 0;
}
