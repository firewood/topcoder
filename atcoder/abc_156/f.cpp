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

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL k = -1, q = -1, n, x, m;
		cin >> k >> q;
		if (k < 0) return 0;
		vector<LL> d(k);
		for (int i = 0; i < k; ++i) {
			cin >> d[i];
		}
		for (int qi = 0; qi < q; ++qi) {
			cin >> n >> x >> m;
			LL sum = x;
			LL zc = 0;
			for (int i = 0; i < k; ++i) {
				LL e = d[i] % m;
				LL c = (n - 1) / k + (((n - 1) % k) >= i + 1);
				sum += e * c;
				if (e == 0) {
					zc += c;
				}
			}
			LL ans = n - 1 - (sum / m - x / m + zc);
			cout << ans << endl;
		}
	}
	return 0;
}
