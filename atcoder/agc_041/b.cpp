// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	const LL INF = 1LL << 60;
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, m, v, p;
		cin >> n >> m >> v >> p;
		if (n < 1) return 0;
		vector<LL> a(n), sum(n + 1);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n; ++i) {
			sum[i + 1] = sum[i] + a[i];
		}
		int left = -1, right = n;
		while (right - left > 1) {
			int mid = (right + left) / 2;
			bool ok = true;
			if (mid >= n - p) {
				;
			} else if (a[mid] + m < a[n - p]) {
				ok = false;
			} else {
				LL votes = max(0LL, (v - (p - 1)- mid)) * m;
				LL r = (a[mid] + m) * (n - p + 1 - mid) - (sum[n - p + 1] - sum[mid]);
				ok = r >= votes;
			}
			if (ok) {
				right = mid;
			} else {
				left = mid;
			}
		}
		int ans = n - left - 1;
		cout << ans << endl;
	}
	return 0;
}
