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

static const int64_t MOD = 998244353;

struct modint {
	int64_t x;
	modint() { }
	modint(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modint operator+(int y) { return (x + y + MOD) % MOD; }
	modint operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modint operator-(int y) { return (x - y + MOD) % MOD; }
	modint operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modint operator*(int y) { return (x * y) % MOD; }
	modint operator*=(int y) { x = (x * y) % MOD; return *this; }
	modint operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modint operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modint modinv(int a) { return modpow(a, MOD - 2); }
	static modint modpow(int a, int b) {
		modint x = a, r = 1;
		for (; b > 0; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

class MBIT {
	std::vector<modint> bit;
	int64_t size;
public:
	MBIT() { }
	MBIT(int64_t sz) { init(sz); }
	void init(int64_t sz) {
		bit = std::vector<modint>((size = sz) + 1, 0);
	}
	modint sum(int64_t i) {
		modint s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int64_t i, int x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

vector<int> get_order(const vector<int>& a) {
	vector<int> r(a.size());
	map<int, int> m;
	for (auto x : a) {
		m[x] = 0;
	}
	int seq = 0;
	for (auto &kv : m) {
		kv.second = seq++;
	}
	for (int i = 0; i < a.size(); ++i) {
		r[i] = m[a[i]];
	}
	return r;
}

modint solve(int N, std::vector<int> A) {
	modint ans = 0, half = modint::modinv(2);
	MBIT bit(N + 2);
	vector<int> order = get_order(A);
	for (int i = 0; i < N; ++i) {
		ans += bit.sum(order[i] + 1) * modint::modpow(2, i);
		bit.add(order[i] + 1, modint::modpow(half, i + 1));
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
