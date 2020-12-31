#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
	LL n, q, t, u, v, tdiff = 0, diff[2] = {};
	cin >> n >> q;
	vector<LL> h(n);
	for (LL i = 0; i < n; ++i) {
		cin >> h[i];
	}
	map<LL, LL> m;
	for (LL i = 1; i < n; i += 2) {
		LL d = h[i] - h[i - 1];
		m[d] += 1;
		if (i < n - 1) {
			d = h[i] - h[i + 1];
			m[d] += 1;
		}
	}
	for (LL i = 0; i < q; ++i) {
		cin >> t;
		if (t == 1) {
			cin >> v;
			tdiff += v;
			diff[0] += v;
		} else if (t == 2) {
			cin >> v;
			tdiff -= v;
			diff[1] += v;
		} else {
			cin >> u >> v;
			--u;
			if (u % 2) {
				LL d = h[u] - h[u - 1];
				m[d] -= 1;
				if (u < n - 1) {
					d = h[u] - h[u + 1];
					m[d] -= 1;
				}
				h[u] += v;
				d = h[u] - h[u - 1];
				m[d] += 1;
				if (u < n - 1) {
					d = h[u] - h[u + 1];
					m[d] += 1;
				}
			} else {
				if (u > 0) {
					LL d = h[u - 1] - h[u];
					m[d] -= 1;
				}
				if (u < n - 1) {
					LL d = h[u + 1] - h[u];
					m[d] -= 1;
				}
				h[u] += v;
				if (u > 0) {
					LL d = h[u - 1] - h[u];
					m[d] += 1;
				}
				if (u < n - 1) {
					LL d = h[u + 1] - h[u];
					m[d] += 1;
				}
			}
		}
		cout << m[tdiff] << endl;
	}
	return 0;
}
