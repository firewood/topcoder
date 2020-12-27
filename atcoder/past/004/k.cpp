#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

const LL MOD = 1000000000;

class BIT {
	std::vector<long long> bit;
	long long size;
public:
	BIT() { }
	BIT(long long sz) { init(sz); }
	void init(long long sz) {
		bit = std::vector<long long>((size = sz) + 1);
	}
	long long sum(long long i) {
		LL s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(long long i, long long x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

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

int main() {
	LL k, q, a, b;
	cin >> k;
	vector<vector<int>> cnt(k, vector<int>(21));
	vector<LL> inversion(k);
	vector<modll> tcnt(21, 0);
	vector<LL> n(k);
	for (LL i = 0; i < k; ++i) {
		BIT bit(24);
		cin >> n[i];
		for (LL j = 0; j < n[i]; ++j) {
			cin >> a;
			cnt[i][a] += 1;
			bit.add(a, 1);
			inversion[i] += j + 1 - bit.sum(a);
		}
	}
	cin >> q;
	modll ans = 0;
	LL tl = 0;
	for (LL i = 0; i < q; ++i) {
		cin >> b;
		--b;
		modll sum = 0;
		ans += inversion[b];
		for (LL j = 20; j >= 1; --j) {
			ans += sum * cnt[b][j];
			sum += tcnt[j];
		}
		for (LL j = 1; j <= 20; ++j) {
			tcnt[j] += cnt[b][j];
		}
		tl += n[b];
	}
	cout << ans << endl;
	return 0;
}
