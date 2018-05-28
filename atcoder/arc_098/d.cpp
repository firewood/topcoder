// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL n;
	cin >> n;
	vector<LL> a(n + 1);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	a[n] = (1 << 30) - 1;
	LL ans = 0;
	LL left = 0, x = 0;
	for (LL i = 0; i <= n; ++i) {
		while (left < i && (((x ^ a[i]) != (x | a[i])) || i == n)) {
			LL d = i - left;
			ans += d;
			x ^= a[left];
			++left;
		}
		x ^= a[i];
	}
	cout << ans << endl;
	return 0;
}
