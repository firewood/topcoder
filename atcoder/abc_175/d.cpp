// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, k, ans = -(1LL << 60);
		cin >> n >> k;
		if (n < 0) return 0;
		vector<LL> p(n), c(n);
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
			--p[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> c[i];
		}
		for (LL i = 0; i < n; ++i) {
			vector<LL> vis(n, -1), hist(n, -1);
			LL s = 0;
			LL pos = i;
			for (LL j = 0; j < k; ++j) {
				pos = p[pos];
				if (vis[pos] >= 0) {
					LL period = j - vis[pos];
					LL loops = (k - j - 2) / period;
					if (loops > 1) {
						j += period * loops;
						s += (s - hist[pos]) * loops;
					}
				}
				vis[pos] = j;
				hist[pos] = s;
				s += c[pos];
				ans = max(ans, s);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
