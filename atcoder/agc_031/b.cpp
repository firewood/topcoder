// B.

#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef long long LL;
static const LL MOD = 1000000007LL;

int n;
vector<int> c;

LL solve() {
	vector<LL> memo = vector<LL>(n + 1, 1);
	vector<int> p(200001, -1);
	LL r = 1;
	p[c[0]] = 0;
	for (int i = 1; i < n; ++i) {
		if (c[i] != c[i - 1]) {
			if (p[c[i]] >= 0) {
				r = (r + memo[p[c[i]]]) % MOD;
			}
			p[c[i]] = i;
		}
		memo[i] = r;
	}
	return r;
}

int main(int argc, char *argv[]) {
	cin >> n;
	c = vector<int>(n + 1, -1);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	LL ans = solve();
	cout << ans << endl;
	return 0;
}
