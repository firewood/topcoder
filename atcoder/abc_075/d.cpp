// D.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LLLL;

int main(int argc, char *argv[])
{
	LL n, k;
	cin >> n >> k;
	vector<LLLL> v;
	for (LL i = 0; i < n; ++i) {
		LL x, y;
		cin >> x >> y;
		v.push_back(LLLL(x, y));
	}
	sort(v.begin(), v.end());
	LL ans = 1LL << 62;
	for (LL i = 0; i < n; ++i) {
		vector<LL> w;
		LL left = 1LL << 62, right = -(1LL << 62);
		for (LL j = i; j < n; ++j) {
			left = min(left, v[j].first);
			right = max(right, v[j].first);
			w.push_back(v[j].second);
			if (right > left && w.size() >= k) {
				sort(w.begin(), w.end());
				for (LL l = 0; l <= w.size() - k; ++l) {
					for (LL m = l + k - 1; m < w.size(); ++m) {
						LL d = w[m] - w[l];
						if (d > 0) {
							ans = min(ans, (right - left) * d);
							break;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
