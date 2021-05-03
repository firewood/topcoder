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
#include <random>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;

LL solve(LL N, LL L, LL R, vector<LL> c) {
	LL ans = 0;
	map<LL, LL> lc, rc;
	for (int i = 0; i < N; i++) {
		if (i < L) {
			lc[c[i]] += 1;
		} else {
			if (lc.find(c[i]) != lc.end() && lc[c[i]] > 0) {
				lc[c[i]] -= 1;
				--L;
				--R;
			} else {
				rc[c[i]] += 1;
			}
		}
	}
	if (R > L) {
		swap(lc, rc);
		swap(L, R);
	}
	for (auto& kv : lc) {
		if (kv.second >= 2) {
			LL mx = (L - R) / 2;
			mx = min(mx, kv.second / 2);
			ans += mx;
			kv.second -= mx * 2;
			L -= mx * 2;
		}
	}

	ans += R;
	L -= R;
	ans += L;

	return ans;
}

int main() {
	LL t, N, L, R;
	cin >> t;
	for (LL q = 0; q < t; ++q) {
		cin >> N >> L >> R;
		std::vector<LL> c(N);
		for (int i = 0; i < N; i++) {
			cin >> c[i];
		}
		LL ans = solve(N, L, R, c);
		cout << ans << endl;
	}
	return 0;
}
