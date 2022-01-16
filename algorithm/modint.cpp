#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;

typedef long double LD;
const int64_t MOD = 1000000007;
const LD EPS = 1e-10;
static const size_t TABLE_SIZE = 1000000;		// 1e6

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

static vector<modint> fact(TABLE_SIZE + 1, 0), inv(TABLE_SIZE + 1, 0);

static __inline void build_fact_table() {
	if (!fact[0]) {
		fact[0] = 1;
		for (int i = 1; i <= TABLE_SIZE; ++i) {
			fact[i] = fact[i - 1] * i;
		}
		inv[TABLE_SIZE] = modint::modinv(fact[TABLE_SIZE]);
		for (int i = TABLE_SIZE; i >= 1; --i) {
			inv[i - 1] = inv[i] * i;
		}
	}
}

modint modint::permutation(int n, int r) {
	if (r > n) return 0;
	build_fact_table();
	return fact[n] * inv[n - r];
}

modint modint::combination(int n, int r) {
	if (r > n) return 0;
	build_fact_table();
	return (fact[n] * inv[r]) * inv[n - r];
}

// 重複組合せ
modint modint::nHr(int n, int r) {
	return combination(n + r - 1, r);
}

modint combination_slow(int n, int r) {
	if (r > n) return 0;
	r = min(r, n - r);
	if (r == 0) return 1;
	if (r == 1) return n;
	if (r == 2) return (((long long)n * (n - 1)) / 2) % MOD;
	modint a = 1, b = 1;
	for (int i = 0; i < r; ++i) {
		a *= n - i;
		b *= i + 1;
	}
	return a * modint::modinv(b);
}

struct Matrix {
	size_t size;
	vector<vector<modint>> e;

	Matrix(size_t size_) {
		size = size_;
		e = vector<vector<modint>>(size, vector<modint>(size, 0));
	}

	void setIdentity() {
		for (size_t i = 0; i < size; ++i) {
			e[i][i] = 1;
		}
	}

	Matrix mul(const Matrix& a) {
		Matrix r(size);
		for (size_t i = 0; i < size; ++i) {
			for (size_t j = 0; j < size; ++j) {
				for (size_t k = 0; k < size; ++k) {
					r.e[i][j] += e[i][k] * a.e[k][j];
				}
			}
		}
		return r;
	}

	Matrix pow(int64_t x) {
		Matrix r(size), b = *this;
		r.setIdentity();
		for (; x > 0; x >>= 1) {
			if (x & 1) {
				r = r.mul(b);
			}
			b = b.mul(b);
		}
		return r;
	}
};

int main(int argc, char* argv[]) {
	modint x = 100;
	vector<int> r;
	for (int i = 0; i < 100; ++i) {
		r.push_back(rand() + 2);
		x *= r.back();
	}
	for (int a : r) {
		x /= a;
	}
	assert(x == 100);

	for (int a = 0; a <= 100; ++a) {
		for (int b = 0; b <= 100; ++b) {
			assert(modint::combination(a, b) == combination_slow(a, b));
		}
	}

	return 0;
}
