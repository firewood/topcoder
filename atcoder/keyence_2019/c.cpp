// C.

#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<LL> a(n), b(n), c, d;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] > b[i]) {
			c.push_back(a[i] - b[i]);
		} else if (a[i] < b[i]) {
			d.push_back(b[i] - a[i]);
		}
	}
	LL x = accumulate(c.begin(), c.end(), 0LL);
	LL y = accumulate(d.begin(), d.end(), 0LL);
	int ans = 0;
	if (y > x) {
		ans = -1;
	} else if (y > 0) {
		int i = 0;
		sort(c.rbegin(), c.rend());
		sort(d.rbegin(), d.rend());
		LL p = 0, q = 0;
		for (LL r : d) {
			++ans;
			q = r;
			while (q > 0) {
				if (!p) {
					++ans;
					p = c[i++];
				}
				LL e = min(p, q);
				p -= e;
				q -= e;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
