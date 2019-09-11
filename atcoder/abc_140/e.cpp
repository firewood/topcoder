// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	while (true) {
		LL n = -1;
		cin >> n;
		if (n <= 0) break;
		vector<int> p(n), r(n + 1);
		for (int i = 0; i < n; ++i) {
			cin >> p[i];
			r[p[i]] = i;
		}
		set<LL> s;
		s.insert(-2);
		s.insert(-1);
		s.insert(n);
		s.insert(n + 1);
		LL ans = 0;
		for (LL i = n; i > 0; --i) {
			auto c = s.lower_bound(r[i]);
			auto b = c, d = c;
			--b, ++d;
			auto a = b;
			--a;
			s.insert(r[i]);
//			if (*b >= 0) {
				ans += i * (*b - max(0LL, *a + 1) + 1) * (min(n - 1, *c - 1) - r[i] + 1);
//			}
//			if (*c < n) {
				ans += i * (r[i] - max(0LL, *b + 1) + 1) * (min(n - 1, *d - 1) - *c + 1);
//			}
		}
		cout << ans << endl;
	}
	return 0;
}
