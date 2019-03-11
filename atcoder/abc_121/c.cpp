// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LLLL;

int main(int argc, char *argv[]) {
	LL n, m;
	cin >> n >> m;
	vector<LLLL> v;
	for (LL i = 0; i < n; ++i) {
		LL a, b;
		cin >> a >> b;
		v.push_back(LLLL(a, b));
	}
	sort(v.begin(), v.end());
	LL ans = 0;
	for (auto kv : v) {
		LL a = min(m, kv.second);
		ans += a * kv.first;
		m -= a;
		if (m <= 0) {
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
