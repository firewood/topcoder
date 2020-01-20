// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

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

vector<int> gen_primes(int m) {
	vector<int> primes;
	primes.push_back(2);
	for (int i = 3; i <= m; i += 2) {
		for (int prime : primes) {
			if (i < prime * prime) {
				primes.push_back(i);
				break;
			}
			if ((i % prime) == 0) {
				break;
			}
		}
	}
	return primes;
}

int main(int argc, char* argv[]) {
	vector<int> primes = gen_primes(100005);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		map<int, int> m;
		for (int i = 0; i < n; ++i) {
			int x = a[i];
			for (int p : primes) {
				if ((x % p) == 0) {
					int c = 0;
					while ((x % p) == 0) {
						++c;
						x /= p;
					}
					m[p] = max(m[p], c);
				}
			}
			if (x > 1) {
				m[x] = 1;
			}
		}
		modll lcm = 1;
		for (auto kv : m) {
			for (int i = 0; i < kv.second; ++i) {
				lcm *= kv.first;
			}
		}
		modll ans = 0;
		for (int i = 0; i < n; ++i) {
			modll x = modll::modinv(a[i]);
			x *= lcm;
			ans += x;
		}
		cout << ans << endl;
	}
	return 0;
}
