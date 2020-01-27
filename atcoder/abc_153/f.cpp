// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

class BIT {
	std::vector<LL> bit;
	LL size;
public:
	BIT() { }
	BIT(LL sz) { init(sz); }
	void init(LL sz) {
		bit = std::vector<LL>((size = sz) + 1);
	}
	LL sum(LL i) {
		LL s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(LL i, LL x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, d, a, x, h, ans = 0;
		cin >> n >> d >> a;
		if (n <= 0) return 0;
		set<LL> s;
		vector<pair<LL, LL>> v;
		for (LL i = 0; i < n; ++i) {
			cin >> x >> h;
			v.push_back({ x, h });
			s.insert(x);
			s.insert(x + 2 * d);
		}
		sort(v.begin(), v.end());
		BIT bit(s.size() + 1);
		map<LL, LL> m;
		LL seq = 0;
		for (LL x : s) {
			m[x] = ++seq;
		}
		for (LL i = 0; i < n; ++i) {
			LL need = (v[i].second - bit.sum(m[v[i].first]) + a - 1) / a;
			if (need > 0) {
				bit.add(m[v[i].first], need * a);
				bit.add(m[v[i].first + 2 * d] + 1, -need * a);
				ans += need;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
