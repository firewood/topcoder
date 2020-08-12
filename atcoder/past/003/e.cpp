// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;

int main() {
	int n, m, q, a, b, type;
	cin >> n >> m >> q;
	vector<int> c(n);
	vector<vector<int>> e(n);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		--a, --b;
		e[a].emplace_back(b);
		e[b].emplace_back(a);
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int w = 0; w < q; ++w) {
		cin >> type >> a;
		--a;
		if (type == 1) {
			cout << c[a] << endl;
			for (int x : e[a]) {
				c[x] = c[a];
			}
		} else {
			cout << c[a] << endl;
			cin >> b;
			c[a] = b;
		}
	}
	return 0;
}
