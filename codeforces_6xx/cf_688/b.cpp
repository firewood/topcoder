#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
const LL INF = 1LL << 60;

int main() {
	LL T, n;
	cin >> T;
	for (int tt = 0; tt < T; ++tt) {
		cin >> n;
		vector<LL> a(n);
		for (LL i = 0; i < n; ++i) {
			cin >> a[i];
		}
		LL sum = 0;
		for (LL i = 1; i < n; ++i) {
			sum += abs(a[i - 1] - a[i]);
		}
		LL ans = sum;
		for (LL i = 1; i < n; ++i) {
			if (i == 1 || i == n - 1) {
				ans = min(ans, sum - abs(a[i - 1] - a[i]));
			}
			if (i < n - 1) {
				ans = min(ans, sum - (abs(a[i - 1] - a[i]) + abs(a[i + 1] - a[i]) - abs(a[i + 1] - a[i - 1])));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
