// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	LL n, m, k, sum = 0;
	cin >> n >> m >> k;
	vector<LL> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	int ai = n - 1, bi = 0, c = n, ans = 0;
	while (sum > k && ai >= 0) {
		sum -= a[ai];
		--ai;
		--c;
	}
	while (true) {
		while (bi < m && sum + b[bi] <= k) {
			sum += b[bi];
			++bi;
			++c;
		}
		ans = max(ans, c);
		if (ai < 0) {
			break;
		}
		sum -= a[ai];
		--ai;
		--c;
	}
	cout << ans << endl;
	return 0;
}
