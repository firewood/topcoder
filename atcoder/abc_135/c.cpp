// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<LL> a(n + 1), b(n);
	for (int i = 0; i < n + 1; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	LL ans = 0;
	for (int i = 0; i < n; ++i) {
		LL x = min(a[i], b[i]);
		ans += x;
		b[i] -= x;
		LL y = min(a[i + 1], b[i]);
		a[i + 1] -= y;
		ans += y;
	}
	cout << ans << endl;
	return 0;
}
