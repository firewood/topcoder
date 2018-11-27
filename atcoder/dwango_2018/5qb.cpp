// B.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	int sz = (n * (n + 1)) / 2;
	vector<LL> a(n), v(sz);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int si = 0;
	for (int i = 0; i < n; ++i) {
		LL c = 0;
		for (int j = i; j < n; ++j) {
			c += a[j];
			v[si++] = c;
		}
	}
	LL ans = 0;
	for (int b = 40; b >= 0; --b) {
		LL x = 1LL << b;
		sort(v.rbegin(), v.rend());
		LL c = 0;
		for (int i = 0; i < sz; ++i) {
			if (!(v[i] & x)) {
				break;
			}
			++c;
			v[i] &= ~x;
		}
		if (c >= k) {
			ans |= x;
			v.resize(c);
		}
	}
	cout << ans << endl;
	return 0;
}
