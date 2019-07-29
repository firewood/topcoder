// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<LL> a(n);
	int neg_cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		neg_cnt += a[i] < 0;
		a[i] = abs(a[i]);
	}
	sort(a.begin(), a.end());
	if (neg_cnt % 2) {
		a[0] = -a[0];
	}
	LL ans = accumulate(a.begin(), a.end(), 0LL);
	cout << ans << endl;
	return 0;
}
