// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[]) {
	LL n, x;
	cin >> n >> x;
	vector<LL> a(n + 1);
	for (LL i = 0; i < n; ++i) {
		cin >> a[i];
	}
	a[n] = x;
	sort(a.begin(), a.end());
	LL ans = a[n] - a[n - 1];
	for (LL i = 1; i < n; ++i) {
		ans = min(ans, gcd(ans, a[i] - a[i - 1]));
	}
	cout << ans << endl;
	return 0;
}
