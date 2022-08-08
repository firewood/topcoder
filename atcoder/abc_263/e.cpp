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

const int64_t MOD = 998244353;

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
	static modint permutation(int n, int r);
	static modint combination(int n, int r);
	static modint nHr(int n, int r);
};

class BIT {
	std::vector<modint> bit;
	int64_t size;
public:
	BIT() { }
	BIT(int64_t sz) { init(sz); }
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

modint solve(int N, std::vector<int> A) {
	BIT bit(N);
	for (int i = N - 2; i >= 0; --i) {
		modint sum = bit.sum(i + A[i] + 1) - bit.sum(i + 1);
		bit.add(i + 1, (sum + 1) * modint::modinv(A[i]) + 1);
	}
	return bit.sum(1);
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> A(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
