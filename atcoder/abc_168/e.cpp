#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> LLLL;

const LL MOD = 1000000007;
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

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, a, b;
		cin >> n;
		if (n < 0) return 0;
		map<LLLL, LL> m;
		map<LLLL, LL> zm;
		LL zc = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			LL g = gcd(a, b);
			if (a == 0 && b == 0) {
				++zc;
				continue;
			} else if (a == 0) {
				b = -1;
			} else if (b == 0) {
				a = 1;
			} else {
				a /= g, b /= g;
			}
			if (a < 0) {
				a = -a;
				b = -b;
			}
			m[LLLL(a, b)] += 1;
		}
		set<LLLL> s;
		modll ans = 1;
		for (auto kv : m) {
			if (s.find(kv.first) != s.end()) continue;
			s.insert(kv.first);
			LLLL dis(kv.first.second, -kv.first.first);
			auto it = m.find(dis);
			LL dc = 0;
			if (it != m.end()) {
				dc += it->second;
				s.insert(dis);
			}
			dis = LLLL(-kv.first.second, kv.first.first);
			it = m.find(dis);
			if (it != m.end()) {
				dc += it->second;
				s.insert(dis);
			}
			if (dc > 0) {
				modll x = modll::modpow(2, kv.second);
				modll y = modll::modpow(2, dc);
				x -= 1;
				y -= 1;
				x += y;
				x += 1;
				ans *= x;
			} else {
//				cout << kv.first.first << " " << kv.first.second << endl;
				ans *= modll::modpow(2, kv.second);
			}
		}
		ans -= 1;
		ans += zc;
		cout << ans << endl;
	}
	return 0;
}
