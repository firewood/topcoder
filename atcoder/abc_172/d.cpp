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
		LL ans = 0;
		vector<int> f(n + 1, 0);
		for (LL i = 1; i <= n; ++i) {
			for (LL j = i; j <= n; j += i) {
				f[j] += 1;
			}
			ans += i * f[i];
		}
		cout << ans << endl;
	}
	return 0;
}
