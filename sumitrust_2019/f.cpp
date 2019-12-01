// F.

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
		LL t1 = -1, t2, a1, a2, b1, b2;
		cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
		if (t1 < 0) return 0;
		LL p = (a1 - b1) * t1, q = (a2 - b2) * t2;
		if (p < 0) {
			p = -p, q = -q;
		}
		if (p + q == 0) {
			cout << "infinity" << endl;
		} else {
			LL ans = 0;
			if (p + q < 0) {
				LL r = p / -(p + q), s = p % -(p + q);
				ans = r * 2 + (s != 0);
			}
			cout << ans << endl;
		}
	}
	return 0;
}
