// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
typedef long long LL;

const LL MOD = 1000000007;

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

LL solve(LL n, LL k, vector<LL> a) {
	modll ans = 0;
	LL zc = 0, r = k;
	vector<LL> pos, neg;
	for (LL i = 0; i < n; ++i) {
		if (a[i] > 0) {
			pos.emplace_back(a[i]);
		} else if (a[i] == 0) {
			++zc;
		} else {
			neg.emplace_back(-a[i]);
		}
	}
	LL nc = min(LL(neg.size() & ~1), k & ~1);
	if (nc + pos.size() >= k) {
		sort(pos.rbegin(), pos.rend());
		sort(neg.rbegin(), neg.rend());
		LL pi = 0, ni = 0;
		ans = 1;
		while (r > 0) {
			LL pp = pi + 2 <= pos.size() ? pos[pi] * pos[pi + 1] : 0;
			LL nn = ni + 2 <= neg.size() ? neg[ni] * neg[ni + 1] : 0;
			if (r >= 2 && (nn > pp || pi >= pos.size() - 1)) {
				r -= 2;
				ans *= int(MOD - neg[ni++]);
				ans *= int(MOD - neg[ni++]);
			} else {
				--r;
				ans *= int(pos[pi++]);
			}
		}
	} else if (!zc) {
		sort(neg.begin(), neg.end());
		ans = 1;
		for (auto x : neg) {
			if (r-- <= 0) break;
			ans *= int(MOD - x);
		}
		for (auto x : pos) {
			if (r-- <= 0) break;
			ans *= int(x);
		}
	}

	return ans;
}

LL solve2(LL n, LL k, vector<LL> a) {
	int seq[8] = { 0,1,2,3,4,5,6,7 };
	LL mx = -1LL << 60;
	do {
		LL x = 1;
		for (LL i = 0; i < k; ++i) {
			x *= a[seq[i]];
		}
		mx = max(mx, x);
	} while (next_permutation(seq, seq + n));
	return (mx + MOD) % MOD;
}

int main(int argc, char* argv[]) {
#ifdef _DEBUG
	for (int t = 0; t < 1000; ++t) {
		LL n = (rand() % 4) + 1;
		LL k = 0;
		while (k <= 0 || k > n) {
			k = (rand() % 4) + 1;
		}
		vector<LL> a(n);
		for (LL i = 0; i < n; ++i) {
			a[i] = (rand() % 20) - 10;
		}
		LL p = solve(n, k, a);
		LL q = solve2(n, k, a);
		if (p != q) {
			break;
		}
	}
#endif

	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, k = -1;
		cin >> n >> k;
		if (n < 0) return 0;
		vector<LL> a(n);
		for (LL i = 0; i < n; ++i) {
			cin >> a[i];
		}
		LL ans = solve(n, k, a);
		cout << ans << endl;
	}
	return 0;
}
