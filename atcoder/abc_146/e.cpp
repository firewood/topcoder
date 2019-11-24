// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
typedef long long LL;

int main(int argc, char* argv[]) {

#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, k = -1, ans = 0;
		cin >> n >> k;
		if (n < 0) return 0;
		vector<LL> a(n), sum(n + 1);
		map<LL, LL> m;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		if (k > 1) {
			m[0] = 1;
			for (int i = 0; i < n; ++i) {
				sum[i + 1] = (sum[i] + a[i] + k - 1) % k;
				ans += m[sum[i + 1]];
				m[sum[i + 1]] += 1;
				if (i >= k - 2) {
					m[sum[i + 2 - k]] -= 1;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
