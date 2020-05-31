// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

LL solve(int n, vector<int>& a) {
	if (n == 0) {
		return a[0] == 1 ? 1 : -1;
	}
	vector<LL> vmx(n + 2);
	LL mn = 0;
	for (int i = n; i >= 0; --i) {
		LL curr = a[i];
		LL upper = 1LL << min(60, i);
		mn = (mn + 1) / 2 + curr;
		if (mn > upper) return -1;
		vmx[i] = min(vmx[i + 1] + curr, upper);
	}
	LL ans = 1 + a[n], mx = 1;
	for (int i = 1; i < n; ++i) {
		mx = min(vmx[i], (mx - a[i - 1]) * 2);
		ans += mx;
	}
	return ans;
}

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<int> a(n + 1);
		for (int i = 0; i <= n; ++i) {
			cin >> a[i];
		}
		cout << solve(n, a) << endl;
	}
	return 0;
}
