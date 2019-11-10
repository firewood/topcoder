// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
static const LL MOD = 998244353;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, mx = 0;
		cin >> n;
		if (n <= 0) return 0;
		vector<int> d(n);
		map<int, int> m;
		for (int i = 0; i < n; ++i) {
			cin >> d[i];
			m[d[i]] += 1;
			mx = max(mx, d[i]);
		}
		LL ans = 0;
		if (d[0] == 0 && m[0] == 1) {
			ans = 1;
			for (int i = 1; i <= mx; ++i) {
				if (!m[i]) {
					ans = 0;
				} else {
					for (int j = 0; j < m[i]; ++j) {
						ans = (ans * m[i - 1]) % MOD;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
