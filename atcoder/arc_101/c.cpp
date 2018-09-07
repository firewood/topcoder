// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	vector<LL> a, b;
	LL n, k;
	cin >> n >> k;
	for (LL i = 0; i < n; ++i) {
		LL x;
		cin >> x;
		if (x >= 0) {
			a.push_back(x);
		} else {
			b.push_back(-x);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	LL ans = a.size() >= k ? a[k - 1] : (1LL << 60);
	if (b.size() >= k) {
		ans = min(ans, b[k - 1]);
	}
	for (LL i = 1; i < k; ++i) {
		LL j = k - i;
		if (a.size() >= i && b.size() >= j) {
			ans = min(ans, a[i - 1] * 2 + b[j - 1]);
			ans = min(ans, a[i - 1] + b[j - 1] * 2);
		}
	}
	cout << ans << endl;
	return 0;
}
