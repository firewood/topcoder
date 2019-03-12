// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[]) {
	int n, m, a, b, ans = 0;
	cin >> n >> m;
	vector<II> v(m);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[i].first = -a;
		v[i].second = b;
	}
	sort(v.begin(), v.end());
	a = b = n + 1;
	for (auto kv : v) {
		int p = -kv.first, q = kv.second;
		if (q >= b) {
			continue;
		}
		if (q > a) {
			b = q;
			continue;
		}
		++ans;
		a = p, b = q;
	}
	cout << ans << endl;
	return 0;
}
