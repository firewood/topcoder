// I.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

int main() {
	LL n, q, a, b, type;
	cin >> n >> q;
	vector<int> r(n), c(n);
	bool f = false;
	for (int i = 0; i < n; ++i) {
		r[i] = i, c[i] = i;
	}
	for (int i = 0; i < q; ++i) {
		cin >> type;
		switch (type) {
		case 1:
			cin >> a >> b;
			--a, --b;
			if (f) {
				swap(c[a], c[b]);
			} else {
				swap(r[a], r[b]);
			}
			break;
		case 2:
			cin >> a >> b;
			--a, --b;
			if (f) {
				swap(r[a], r[b]);
			} else {
				swap(c[a], c[b]);
			}
			break;
		case 3:
			f = !f;
			break;
		case 4:
			cin >> a >> b;
			--a, --b;
			if (f) {
				swap(a, b);
			}
			cout << (n * r[a] + c[b]) << endl;
			break;
		}
	}
	return 0;
}
