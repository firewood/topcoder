// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <map>
#include <bitset>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		LL ans = 0, cnt = 1, index = 0;
		vector<int> a(n);
		for (LL i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a.rbegin(), a.rend());
		for (LL t = 1; t < n; ++t) {
			ans += a[index];
			if (++cnt >= 2) {
				cnt = 0;
				++index;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
