#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;

static const LL INF = 1LL << 60;
static const long long MOD = 998244353;
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

int nHr(int n, int r) {
	return combination(n + r - 1, r);
}

LL solve(int N, int M) {
	modll ans = 1;
	vector<vector<int>> c(M + 1);
	vector<int> f(M + 1);
	for (LL i = 2; i <= M; ++i) {
		if (!f[i]) {
			for (LL k = i; k <= M; k += i) {
				f[k] = 1;
				c[k].emplace_back(1);
			}
			for (LL j = i * i; j <= M; j *= i) {
				for (LL k = j; k <= M; k += j) {
					c[k].back() += 1;
				}
			}
		}
		modll x = 1;
		for (auto y : c[i]) {
			x *= nHr(N, y);
		}
		ans += x;
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	cout << solve(N, M) << endl;
	return 0;
}
