// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;
typedef long long LL;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1;
		cin >> n;
		if (n < 0) return 0;
		set<LL> s;
		for (LL x = 1; x * x <= n; ++x) {
			if ((n % x) == 0) {
				if (x > 1) {
					LL y = n;
					while ((y % x) == 0) {
						y /= x;
					}
					if (y % x == 1) {
						s.insert(x);
					}
				}
				LL d = n / x;
				LL y = n;
				while ((y % d) == 0) {
					y /= d;
				}
				if (y % d == 1) {
					s.insert(d);
				}
			}
		}
		--n;
		for (LL x = 1; x * x <= n; ++x) {
			if ((n % x) == 0) {
				if (x > 1) {
					s.insert(x);
				}
				s.insert(n / x);
			}
		}
		s.erase(1);
		LL ans = s.size();
		cout << ans << endl;
	}
	return 0;
}
