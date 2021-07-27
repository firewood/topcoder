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

class BIT {
	std::vector<int64_t> bit;
	int64_t size;
public:
	BIT() { }
	BIT(int64_t sz) { init(sz); }
	void init(int64_t sz) {
		bit = std::vector<int64_t>((size = sz) + 1);
	}
	int64_t sum(int64_t i) {
		int64_t s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int64_t i, int64_t x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

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
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

modint solve(int N, int K, std::vector<std::string> c, std::vector<int> k) {
	BIT bit(1001);
	vector<int> fixed(1001);
	for (int i = 0; i < K; ++i) {
		fixed[k[i] - 1] = 1;
		if (c[i] == "L") {
			bit.add(1, 1);
			bit.add(k[i], -1);
		} else {
			bit.add(k[i], 1);
		}
	}
	modint ans = 1;
	for (int i = 0; i < N; ++i) {
		if (!fixed[i]) {
			ans *= (K - bit.sum(i + 1));
		}
	}
	return ans;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<std::string> c(K);
	std::vector<int> k(K);
	for (int i = 0; i < K; i++) {
		std::cin >> c[i] >> k[i];
	}
	cout << solve(N, K, c, k) << endl;
	return 0;
}
