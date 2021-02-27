#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <atcoder/math>

using namespace std;

typedef long long LL;

static const LL INF = 1LL << 60;

LL solve(LL x, LL y, LL p, LL q) {
	LL ans = INF;
	for (LL r = x; r < x + y; ++r) {
		for (LL s = p; s < p + q; ++s) {
			pair<LL, LL> result = atcoder::crt({ r, s }, { (x + y) * 2, p + q });
			if (result.second != 0) {
				ans = min(ans, result.first);
			}
		}
	}
	return ans;
}

int main() {
	LL t, x, y, p, q;
	cin >> t;
	for (LL tt = 0; tt < t; ++tt) {
		cin >> x >> y >> p >> q;
		LL ans = solve(x, y, p, q);
		if (ans < 0 || ans >= INF) {
			cout << "infinity" << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}
