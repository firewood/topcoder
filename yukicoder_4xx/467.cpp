#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	LL d[16] = {};
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	LL x, y;
	cin >> x >> y;
	LL z = max(abs(x), abs(y));
	sort(d, d + n);
	LL ans = (z + d[n - 1] - 1) / d[n - 1];
	if (ans > 0 && ans < 3) {
		if (find(d, d + n, z) < (d + n)) {
			ans = 1;
		} else {
			ans = 2;
		}
	}
	cout << ans << endl;
	return 0;
}
