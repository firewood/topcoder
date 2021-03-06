// D.

#include <sstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;
typedef long double LD;
const LL MOD = 1000000007;
const LD EPS = 1e-10;
static const size_t MAX_N = 1000001;

struct modll {
	long long x;
	modll() { }
	modll(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(int y) { return (x + y + MOD) % MOD; }
	modll operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modll operator-(int y) { return (x - y + MOD) % MOD; }
	modll operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modll operator*(int y) { return (x * y) % MOD; }
	modll operator*=(int y) { x = (x * y) % MOD; return *this; }
	modll operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modll operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

modll combination(LL n, LL r) {
	static modll fact[MAX_N + 1], inv[MAX_N + 1];
	if (!fact[0]) {
		fact[0] = 1;
		for (int i = 1; i <= MAX_N; ++i) {
			fact[i] = fact[i - 1] * i;
		}
		inv[MAX_N] = modll::modinv(fact[MAX_N]);
		for (int i = MAX_N; i >= 1; --i) {
			inv[i - 1] = inv[i] * i;
		}
	}
	if (r > n) {
		return 0;
	}
	return (fact[n] * inv[r]) * inv[n - r];
}

int main(int argc, char *argv[])
{
	int n, m;
	cin >> n >> m;
	int mx = sqrt(m);
	vector<int> b;
	for (int i = 2; i <= mx; ++i) {
		if ((m % i) == 0) {
			int cnt = 0;
			while ((m % i) == 0) {
				++cnt;
				m /= i;
			}
			b.push_back(cnt);
		}
	}
	if (m > 1) {
		b.push_back(1);
	}
	modll ans = 1;
	for (int x : b) {
		ans *= combination(x + n - 1, x);
	}
	cout << ans << endl;
	return 0;
}
