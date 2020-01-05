// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, m, x, mx;
		cin >> n;
		if (n < 0) return 0;
		vector<LL> mn(n, 1LL << 30), fulfilled(n), v;
		for (int i = 0; i < n; ++i) {
			mx = 0;
			cin >> m;
			for (int j = 0; j < m; ++j) {
				cin >> x;
				if (x > mn[i]) {
					fulfilled[i] = 1;
				}
				mn[i] = min(mn[i], x);
				mx = max(mx, x);
			}
			if (!fulfilled[i]) {
				v.push_back(mx);
			}
		}
		LL ffs = accumulate(fulfilled.begin(), fulfilled.end(), 0LL);
		sort(v.begin(), v.end());
		LL ans = 0;
		for (int i = 0; i < n; ++i) {
			if (fulfilled[i]) {
				ans += n;
			} else {
				LL pos = lower_bound(v.begin(), v.end(), mn[i] + 1) - v.begin();
				ans += (ffs + v.size() - pos);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
