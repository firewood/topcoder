// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n <= 0) return 0;
		vector<int> a(n), dp(n, 1 << 30);
		dp[0] = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			if (i >= 1) {
				dp[i] = min(dp[i], dp[i - 1] + abs(a[i] - a[i - 1]));
				if (i >= 2) {
					dp[i] = min(dp[i], dp[i - 2] + abs(a[i] - a[i - 2]));
				}
			}
		}
		cout << dp[n - 1] << endl;
	}
	return 0;
}
