// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, k = -1, zc = 0, a, ans;
		cin >> n >> k;
		if (n < 0) return 0;
		vector<LL> neg, pos;
		for (LL i = 0; i < n; ++i) {
			cin >> a;
			if (a > 0) {
				pos.push_back(a);
			} else if (a == 0) {
				++zc;
			} else {
				neg.push_back(a);
			}
		}
		sort(neg.rbegin(), neg.rend());
		sort(pos.begin(), pos.end());
		LL negs = pos.size() * neg.size();
		LL zeros = zc * (pos.size() + neg.size()) + zc * (zc - 1) / 2;
		if (k <= negs) {
			LL left = -1LL << 60, right = 0;
			while (right - left > 1) {
				LL mid = (right + left) / 2;
				LL j = neg.size() - 1;
				LL cnt = 0;
				for (LL a : pos) {
					if (a == 0) continue;
					while (j >= 0 && a * neg[j] < mid) {
						--j;
					}
					cnt += j + 1;
				}
				if (negs - cnt >= k) {
					right = mid;
				} else {
					left = mid;
				}
			}
			ans = left;
		} else if (k <= negs + zeros) {
			ans = 0;
		} else {
			k -= (negs + zeros);
			LL left = -1, right = 1LL << 60;
			LL tot = neg.size() * (neg.size() - 1) / 2 + pos.size() * (pos.size() - 1) / 2;
			while (right - left > 1) {
				LL mid = (right + left) / 2;
				auto calc = [&](const vector<LL> &v) -> LL {
					LL cnt = 0, sz = v.size(), j = sz;
					for (LL i = 0; i < sz; ++i) {
						while (j > 0 && v[i] * v[j - 1] >= mid) {
							--j;
						}
						cnt += sz - j - (j <= i);
					}
					return cnt / 2;
				};
				if (tot - (calc(neg) + calc(pos)) >= k) {
					right = mid;
				} else {
					left = mid;
				}
			}
			ans = left;
		}
		cout << ans << endl;
	}
	return 0;
}
