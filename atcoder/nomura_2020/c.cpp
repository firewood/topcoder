// C.

#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>

using namespace std;

typedef long long LL;

LL solve(int n, vector<int>& a) {
	if (n == 0) {
		return a[0] == 1 ? 1 : -1;
	}
	if (n < 60 && a[n] > (1LL << n)) {
		return -1;
	}
	vector<LL> vmn(n + 1);
	vector<LL> vmx(n + 1);
	vmn[n] = a[n];
	vmx[n] = a[n];
	for (int i = n - 1; i >= 0; --i) {
		LL curr = a[i];
		LL upper = 1LL << min(60, i);
		if (curr > upper) {
			return -1;
		}
		LL nmn = (vmn[i + 1] + 1) / 2 + curr;
		if (nmn > upper) {
			return -1;
		}
		LL nmx = min(vmx[i + 1] + curr, upper);
		vmn[i] = nmn;
		vmx[i] = nmx;
	}
	LL ans = 1 + a[n];
	LL mx = 1;
	for (int i = 1; i < n; ++i) {
		LL next = min(vmx[i], (mx - a[i - 1]) * 2);
		ans += next;
		mx = next;
	}
	return ans;
}

int main(int argc, char* argv[]) {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i <= n; ++i) {
		cin >> a[i];
	}
	LL ans = solve(n, a);
	cout << ans << endl;
	return 0;
}
