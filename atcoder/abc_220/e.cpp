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
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

int64_t solve(int64_t N, int64_t D) {
	modint ans = 0;
	vector<modint> table(max(D + 1, N + 1), 1), cnt(D + 1, 0), sum(D + 1, 0);
	for (int level = 2; level < table.size(); ++level) {
		table[level] = table[level - 1] * 2;
	}
	for (int64_t left = 0; left <= D; ++left) {
		int64_t right = D - left;
		cnt[max(left, right)] += table[left] * table[right];
	}
	for (int64_t i = D / 2; i <= D; ++i) {
		if (i) sum[i] = sum[i - 1];
		sum[i] += cnt[i];
	}
	for (int64_t i = 0; i < N; ++i) {
		ans += sum[min(D, N - 1 - i)] * table[i + 1];
	}
	return ans * 2;
}

int main() {
	int64_t N, D;
	std::cin >> N >> D;
	cout << solve(N, D) << endl;
	return 0;
}
