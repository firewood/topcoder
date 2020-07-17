// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
LL lcm(LL a, LL b) { return (a / gcd(a, b)) * b; }

LL count2(LL x) {
	LL count = 1;
	while ((x % (1LL << count)) == 0) {
		++count;
	}
	return count - 1;
}

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, m;
		cin >> n >> m;
		if (n < 0) return 0;
		vector<LL> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		LL l = a[0] / 2, c = count2(a[0]);
		for (int i = 1; i < n; ++i) {
			l = lcm(l, a[i] / 2);
			if (count2(a[i]) != c) {
				l = 1e18;
				break;
			}
		}
		LL ans = (m / l + 1) / 2;
		cout << ans << endl;
	}
	return 0;
}
