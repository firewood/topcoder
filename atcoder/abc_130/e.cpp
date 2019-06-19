// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;
static const size_t MAX_N = 200050;

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll& r) { return (x + r.x) % MOD; }
	modll operator+=(const modll & r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll & r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll & r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll & r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll & r) { return x = (x * r.x) % MOD; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<LL> s(n), t(m);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> t[i];
	}
	vector<modll> dp(2002, 0);
	for (int i = 0; i < n; ++i) {
		modll sum = 0;
		vector<modll> next = dp;
		LL x = s[i];
		for (int j = 0; j < m; ++j) {
			if (t[j] == x) {
				next[j] += 1;
				next[j] += sum;
			}
			sum += dp[j];
		}
		dp = next;
	}
	modll ans = 1;
	for (int i = 0; i <= 2000; ++i) {
		ans += dp[i];
	}
	cout << ans << endl;
	return 0;
}
