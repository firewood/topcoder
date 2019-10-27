// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	const LL INF = 1LL << 60;
	while (true) {
		LL n = -1, k = -1;
		cin >> n >> k;
		if (n <= 0 || k < 0) break;
		vector<LL> a(n), f(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> f[i];
		}
		sort(a.begin(), a.end());
		sort(f.rbegin(), f.rend());
		LL left = -1, right = INF;
		while (right - left > 1) {
			LL mid = (right + left) / 2;
			LL r = k;
			for (int i = 0; i < n; ++i) {
				LL x = mid / f[i];
				if (x <= 0) {
					r -= a[i];
				} else {
					r -= max(0LL, a[i] - x);
				}
			}
			if (r < 0) {
				left = mid;
			} else {
				right = mid;
			}
		}
		cout << right << endl;
	}
	return 0;
}
