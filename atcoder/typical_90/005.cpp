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

const LL MOD = 1000000007;

struct modint {
	long long x;
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

	Matrix pow(LL x) {
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

int solve1(LL N, LL B, LL K, vector<int> &c) {
	if (N > 10000) return -1;
	vector<modint> dp(B, 0);
	dp[0] = 1;
	modint x = 1;
	for (LL i = 0; i < N; ++i) {
		vector<modint> next(B, 0);
		for (int j = 0; j < B; ++j) {
			for (int k = 0; k < K; ++k) {
				modint d = x * c[k] + j;
				next[d % B] += dp[j];
			}
		}
		dp = next;
		x = (x * 10) % B;
	}
	return dp[0];
}

int solve2(LL N, LL B, LL K, vector<int>& c) {
	if (B > 30) return -1;
	Matrix mat(B);
	for (int j = 0; j < B; ++j) {
		for (int k = 0; k < K; ++k) {
			mat.e[j][(j * 10 + c[k]) % B] += 1;
		}
	}
	return mat.pow(N).e[0][0];
}

int solve3(LL N, LL B, LL K, vector<int>& c) {
	vector<vector<modint>> dp(64, vector<modint>(B, 0));
	for (int k = 0; k < K; ++k) {
		dp[0][c[k] % B] += 1;
	}
	modint d = 10;
	for (int i = 0; i < 62; ++i) {
		for (int j = 0; j < B; ++j) {
			for (int k = 0; k < B; ++k) {
				dp[i + 1][(j * d + k) % B] += dp[i][j] * dp[i][k];
			}
		}
		d = (d * d) % B;
	}
	vector<modint> ans(B, 0);
	d = 10;
	ans[0] = 1;
	for (int i = 0; i < 62; ++i) {
		if (N & (1LL << i)) {
			vector<modint> next(B, 0);
			for (int j = 0; j < B; ++j) {
				for (int k = 0; k < B; ++k) {
					next[(j * d + k) % B] += ans[j] * dp[i][k];
				}
			}
			ans = next;
		}
		d = (d * d) % B;
	}
	return ans[0];
}

int main() {
	LL N, B, K;
	std::cin >> N >> B >> K;
	vector<int> c(K);
	for (int i = 0; i < K; ++i) {
		cin >> c[i];
	}
	cout << solve3(N, B, K, c) << endl;
	return 0;
}
