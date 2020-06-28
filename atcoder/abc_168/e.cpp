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

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, a, b, zc = 0;
		cin >> n;
		if (n < 0) return 0;
		map<LLLL, LL> m;
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
				a = -a, b = -b;
			}
			m[LLLL(a, b)] += 1;
		}
		set<LLLL> s;
		modll ans = 1;
		for (auto kv : m) {
			if (s.find(kv.first) != s.end()) continue;
			s.insert(kv.first);
			LL c = kv.first.second, d = -kv.first.first;
			if (c < 0) {
				c = -c, d = -d;
			}
			LLLL dis(c, d);
			auto it = m.find(dis);
			modll x = modll::modpow(2, kv.second);
			if (it != m.end()) {
				s.insert(dis);
				x += modll::modpow(2, it->second) - 1;
			}
			ans *= x;
		}
		ans += zc - 1;
		cout << ans << endl;
	}
	return 0;
}
