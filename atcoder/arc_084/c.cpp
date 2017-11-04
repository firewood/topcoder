// C.

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n;
	cin >> n;
	vector<LL> a(n), b(n), c(n), d(n), e(n);
	for (LL i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (LL i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (LL i = 0; i < n; ++i) {
		cin >> c[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	LL right = n - 1;
	for (LL i = n - 1; i >= 0; --i) {
		while (right > 0 && b[i] < c[right - 1]) {
			--right;
		}
		if (b[i] < c[right]) {
			d[i] = n - right;
		}
	}
	right = n;
	LL ans = 0, sum = 0;
	for (LL i = n - 1; i >= 0; --i) {
		while (right > 0 && a[i] < b[right - 1]) {
			--right;
			sum += d[right];
		}
		if (right < n && a[i] < b[right]) {
			ans += sum;
		}
	}
	cout << ans << endl;
	return 0;
}
