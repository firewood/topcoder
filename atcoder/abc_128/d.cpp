// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int n, k;
	cin >> n >> k;
	vector<LL> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	LL ans = 0;
	vector<LL> a;
	for (int i = 0; i <= k; ++i) {
		if (i) {
			a.push_back(v[i - 1]);
		}
		vector<LL> b = a;
		for (int j = 0; j <= min(n - i, k - i); ++j) {
			if (j) {
				b.push_back(v[n - j]);
			}
			sort(b.begin(), b.end());
			LL tot = accumulate(b.begin(), b.end(), 0LL);
			for (int l = 0; l < (int)b.size() && l < k - i - j; ++l) {
				if (b[l] < 0) {
					tot -= b[l];
				}
			}
			ans = max(ans, tot);
		}
	}
	cout << ans << endl;
	return 0;
}
