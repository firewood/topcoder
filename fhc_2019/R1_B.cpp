//
// Facebook Hacker Cup 2019 Round 1
// B. Class Treasurer
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

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

int solve(int n, int k, string s) {
	vector<modll> table(n);
	table[0] = 2;
	for (int i = 1; i < n; ++i) {
		table[i] = table[i - 1] * 2;
	}
	modll ans = 0;
	int cnt = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == 'B') {
			if (cnt >= k) {
				ans += table[i];
				cnt = max(0, cnt - 1);
			} else {
				++cnt;
			}
		} else {
			cnt = max(0, cnt - 1);
		}
	}
	return ans;
}

int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		int ans = solve(n, k, s);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
