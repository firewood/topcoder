#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;
map<pair<LL, LL>, LL> memo;

LL solve(LL x, LL i, const vector<LL> &a) {
	if (i >= a.size()) return 1;
	pair<LL, LL> key(x, i);
	if (memo.find(key) != memo.end()) return memo[key];
	LL &w = memo[key];
	LL y = a[i];
	if (i == a.size() - 1) {
		w = (x % y) == 0;
	} else {
		LL r = x % a[i + 1];
		if (r == 0) {
			w = solve(x, i + 1, a);
		} else {
			w = solve(x - r, i + 1, a) + solve(x - r + a[i + 1], i + 1, a);
		}
	}
	return w;
}

int main() {
	LL N, X;
	cin >> N >> X;
	vector<LL> a(N);
	for (LL i = 0; i < N; ++i) {
		cin >> a[i];
	}
	LL ans = solve(X, 0, a);
	cout << ans << endl;
	return 0;
}
