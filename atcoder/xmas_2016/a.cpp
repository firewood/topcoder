// A.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

typedef pair<int, int> II;
typedef map<int, II> IIIMap;

int main(int argc, char *argv[]) {
	int N;
	cin >> N;
	set<int> a;
	for (int i = 0; i <= 16; ++i) {
		a.insert(1 << i);
	}
	IIIMap m;
	for (int x : a) {
		for (int y : a) {
			m[x + y] = II(x, y);
			if (x > y && m.find(x - y) == m.end()) {
				m[x - y] = II(x, -y);
			}
		}
	}
	LL ans = 0, x;
	int l = 0, r = N;
	while (l < r) {
		int d = r - l;
		if (a.find(d) != a.end()) {
			cout << "? " << l << " " << r << endl;
			cin >> x;
			ans += x;
			l = r;
			continue;
		}
		if (m.find(d) != m.end()) {
			II &y = m[d];
			if ((l + y.first) <= N) {
				cout << "? " << l << " " << (l + y.first) << endl;
				cin >> x;
				ans += x;
				if (y.second > 0) {
					cout << "? " << (l + y.first) << " " << (l + y.first + y.second) << endl;
					cin >> x;
					ans += x;
					l = r;
				} else {
					cout << "? " << (l + y.first + y.second) << " " << (l + y.first) << endl;
					cin >> x;
					ans -= x;
					l = r;
				}
				continue;
			}
		}
		int b;
		for (b = 1 << 16; b > 0; b >>= 1) {
			d = r - l - b;
			if (m.find(d) != m.end()) {
				II &y = m[d];
				if ((l + y.first) <= N) {
					cout << "? " << (r - b) << " " << r << endl;
					cin >> x;
					ans += x;
					r -= b;
					break;
				}
			}
		}
		if (!b) {
			d = r - l;
			for (b = 1 << 16; b > 0; b >>= 1) {
				if (b <= d) {
					cout << "? " << (r - b) << " " << r << endl;
					cin >> x;
					ans += x;
					r -= b;
					break;
				}
			}
		}
	}
	cout << "! " << ans << endl;
	return 0;
}
