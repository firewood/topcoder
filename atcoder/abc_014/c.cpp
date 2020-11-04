#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;
static const LL INF = 1LL << 60;

int main() {
	LL n, a, b, ans = 1;
	cin >> n;
#if 1
	vector<LL> sum(1000002);
	for (LL i = 0; i < n; ++i) {
		cin >> a >> b;
		sum[a] += 1;
		sum[b + 1] -= 1;
	}
	// imos
	for (LL i = 1; i <= 1000000; ++i) {
		sum[i] += sum[i - 1];
	}
	ans = *max_element(sum.begin(), sum.end());
#else
	vector<II> v(n);
	for (LL i = 0; i < n; ++i) {
		cin >> a >> b;
		v[i].first = a;
		v[i].second = b;
	}
	sort(v.begin(), v.end());
	map<LL, LL> m;
	LL cnt = 0;
	for (LL i = 0; i < n; ++i) {
		while (!m.empty() && m.begin()->first < v[i].first) {
			cnt -= m.begin()->second;
			m.erase(m.begin());
		}
		++cnt;
		m[v[i].second] += 1;
		ans = max(ans, cnt);
	}
#endif
	cout << ans << endl;
	return 0;
}
