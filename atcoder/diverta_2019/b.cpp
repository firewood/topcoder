// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL r, g, b, n, ans = 0;
	cin >> r >> g >> b >> n;
	for (LL i = 0; i <= n; i += r) {
		for (LL j = 0; i + j <= n; j += g) {
			if (((n - i - j) % b) == 0) {
				ans += 1;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
