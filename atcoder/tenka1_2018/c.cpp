// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

typedef long long LL;

LL solve(int n, vector<LL> &a) {
	int m = (n / 4) * 2 + (n % 2);
	vector<LL> x(a.begin(), a.begin() + m);
	vector<LL> y(a.begin() + m, a.end());
	deque<LL> d;
	int xi = 0, yi = y.size() - 1;
	while (xi < (int)x.size() || yi >= 0) {
		if (xi < (int)x.size()) {
			d.push_back(x[xi++]);
		}
		if (yi >= 0) {
			d.push_front(y[yi--]);
		}
		if (yi >= 0) {
			d.push_back(y[yi--]);
		}
		if (xi < (int)x.size()) {
			d.push_front(x[xi++]);
		}
	}
	vector<LL> b;
	for (LL z : d) {
		b.push_back(z);
	}
	LL ans = 0;
	for (int i = 1; i < n; ++i) {
		ans += abs(b[i] - b[i - 1]);
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	vector<LL> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	LL ans = solve(n, a);
	sort(a.rbegin(), a.rend());
	ans = max(ans, solve(n, a));
	cout << ans << endl;
	return 0;
}
