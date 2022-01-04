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
	std::vector<long long> bit;
	long long size;
public:
	BIT() { }
	BIT(long long sz) { init(sz); }
	void init(long long sz) {
		bit = std::vector<long long>((size = sz) + 1);
	}
	long long sum(long long i) {
		long long s = 0;
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

modint solve(int N, int K, vector<int> P) {
	modint ans = 1;
	BIT bit(N);
	for (int i = 0; i < N; ++i) {
		if ((bit.sum(N) - bit.sum(P[i])) == K) {
			ans *= (N - i);
		}
		bit.add(P[i], 1);
	}
	return ans;
}

int main() {
	int N, K;
	cin >> N >> K;
	std::vector<int> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
	}
	cout << solve(N, K, P) << endl;
	return 0;
}
