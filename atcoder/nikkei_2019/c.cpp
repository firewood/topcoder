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
	vector<int> a(n), b(n);
	vector< pair<int, int> > c;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		c.push_back({ a[i] + b[i], i });
	}
	sort(c.rbegin(), c.rend());
	LL x = 0, y = 0;
	for (int i = 0; i < n; i += 2) {
		x += a[c[i].second];
		if (i + 1 < n) {
			y += b[c[i + 1].second];
		}
	}
	LL ans = x - y;
	cout << ans << endl;
	return 0;
}
