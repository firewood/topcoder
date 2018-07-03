// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, sum = 0;
	cin >> n;
	vector<LL> a(n);
	for (LL i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] -= i;
	}
	sort(a.begin(), a.end());
	LL ans = 1LL << 60;
	for (LL i = max(0LL, n / 2 - 1); i <= n / 2; ++i) {
		LL t = 0;
		for (LL j = 0; j < n; ++j) {
			t += abs(a[j] - a[i]);
		}
		ans = min(ans, t);
	}
	cout << ans << endl;
	return 0;
}
