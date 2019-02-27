// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL a, b, q;
	cin >> a >> b >> q;
	vector<LL> s(a), t(b);
	for (int i = 0; i < a; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < b; ++i) {
		cin >> t[i];
	}
	for (int i = 0; i < q; ++i) {
		LL x;
		cin >> x;
		LL ans = 1LL << 60;
		int y = (int)(lower_bound(s.begin(), s.end(), x) - s.begin());
		for (int j = max(0, y - 1); j <= min(y, (int)s.size() - 1); ++j) {
			LL yc = abs(x - s[j]);
			int z = (int)(lower_bound(t.begin(), t.end(), s[j]) - t.begin());
			for (int k = max(0, z - 1); k <= min(z, (int)t.size() - 1); ++k) {
				LL zc = yc + abs(s[j] - t[k]);
				ans = min(ans, zc);
			}
		}
		y = (int)(lower_bound(t.begin(), t.end(), x) - t.begin());
		for (int j = max(0, y - 1); j <= min(y, (int)t.size() - 1); ++j) {
			LL yc = abs(x - t[j]);
			int z = (int)(lower_bound(s.begin(), s.end(), t[j]) - s.begin());
			for (int k = max(0, z - 1); k <= min(z, (int)s.size() - 1); ++k) {
				LL zc = yc + abs(t[j] - s[k]);
				ans = min(ans, zc);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
