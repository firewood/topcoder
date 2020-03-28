// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL x = -1, y, a, b, c;
		cin >> x >> y >> a >> b >> c;
		if (x < 0) return 0;
		vector<LL> p(a), q(b), r(c);
		for (int i = 0; i < a; ++i) {
			cin >> p[i];
		}
		for (int i = 0; i < b; ++i) {
			cin >> q[i];
		}
		for (int i = 0; i < c; ++i) {
			cin >> r[i];
		}
		sort(p.rbegin(), p.rend());
		sort(q.rbegin(), q.rend());
		sort(r.rbegin(), r.rend());
		p.resize(x);
		q.resize(y);
		r.resize(x + y);
		for (auto z : q) p.emplace_back(z);
		for (auto z : r) p.emplace_back(z);
		sort(p.rbegin(), p.rend());
		LL ans = accumulate(p.begin(), p.begin() + x + y, 0LL);
		cout << ans << endl;
	}
	return 0;
}
