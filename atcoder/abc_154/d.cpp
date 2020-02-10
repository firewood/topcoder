// D.

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
		LL mx = 0;
		LL n = -1, k = -1, sum = 0;
		cin >> n >> k;
		if (n < 0) return 0;
		vector<LL> p(n);
		for (LL i = 0; i < n; ++i) {
			cin >> p[i];
			++p[i];
			if (i >= k) {
				sum -= p[i - k];
			}
			sum += p[i];
			mx = max(mx, sum);
		}
		double ans = (double)mx * 0.5;
		cout << ans << endl;
	}
	return 0;
}
