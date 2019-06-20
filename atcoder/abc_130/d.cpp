// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, k;
	cin >> n >> k;
	vector<LL> sum(n + 10);
	for (LL i = 0; i < n; ++i) {
		LL a;
		cin >> a;
		sum[i + 1] = sum[i] + a;
	}
	LL ans = 0;
	for (LL i = 0; i < n; ++i) {
		LL left = i - 1, right = n - 1;
		if (sum[n] - sum[i] >= k) {
			while (right - left > 1) {
				LL mid = (left + right) / 2;
				if (sum[mid + 1] - sum[i] >= k) {
					right = mid;
				} else {
					left = mid;
				}
			}
			LL p = n - (left + 1);
			ans += p;
		}
	}
	cout << ans << endl;
	return 0;
}
