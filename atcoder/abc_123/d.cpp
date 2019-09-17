// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<LL> a(x), b(y), c(z);
	for (int i = 0; i < x; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < y; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < z; ++i) {
		cin >> c[i];
	}
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	sort(c.rbegin(), c.rend());
	vector<LL> v, w;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			v.push_back(a[i] + b[j]);
		}
	}
	sort(v.rbegin(), v.rend());
	int m = min((int)v.size(), k);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < c.size(); ++j) {
			w.push_back(v[i] + c[j]);
		}
	}
	sort(w.rbegin(), w.rend());
	for (int i = 0; i < k; ++i) {
		cout << w[i] << endl;
	}
	return 0;
}
