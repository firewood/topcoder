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
		LL n = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<LL> a(n), b;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		LL ans = 1000;
		for (int i = 1; i < n; ++i) {
			if (a[i - 1] < a[i]) {
				LL s = ans / a[i - 1];
				ans = ans + s * (a[i] - a[i - 1]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
