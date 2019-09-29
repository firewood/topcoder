// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char* argv[]) {
	while (true) {
		LL a = -1, b = -1;
		cin >> a >> b;
		if (a < 0 || b < 0) break;
		LL g = gcd(a, b);
		LL ans = 1;
		for (LL i = 2; i * i <= g; ++i) {
			if ((g % i) == 0) {
				++ans;
				while ((g % i) == 0) {
					g /= i;
				}
			}
		}
		ans += g > 1;
		cout << ans << endl;
	}
	return 0;
}
