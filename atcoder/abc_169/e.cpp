#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, a, b, ans = 0;
		cin >> n;
		if (n < 0) return 0;
		vector<int> mn(n), mx(n);
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			mn[i] = a;
			mx[i] = b;
		}
		sort(mn.begin(), mn.end());
		sort(mx.rbegin(), mx.rend());
		if (n % 2) {
			ans = mx[n / 2] - mn[n / 2] + 1;
		} else {
			int low = mn[n / 2 - 1] + mn[n / 2];
			int high = mx[n / 2 - 1] + mx[n / 2];
			ans += (high - low) + 1;
		}
		cout << ans << endl;
	}
	return 0;
}
