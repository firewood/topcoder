#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

static const int64_t MOD = 998244353;

struct modint {
	int64_t x;
	modint() { x = 0; }
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

int solve(int N, int D, std::vector<int> p, std::vector<int> q) {
	vector<map<int, modint>> dp(D + 1);
	dp[0][0] = 1;
	for (int i = 0; i < N; ++i) {
		vector<map<int, modint>> next(D + 1);
		for (int j = -1000 - D; j <= 1000 + D; ++j) {
			int da = abs(p[i] - j), db = abs(q[i] - j);
			if (da > D || db > D) continue;
			for (int k = 0; k + da <= D; ++k) {
				for (auto kv : dp[k]) {
					int dist = kv.first + db;
					if (dist <= D) {
						next[k + da][dist] += kv.second;
					}
				}
			}
		}
		dp = next;
	}
	modint ans = 0;
	for (int d = 0; d <= D; ++d) {
		for (auto kv : dp[d]) {
			ans += kv.second;
		}
	}
	return ans;
}

int main() {
	int N, D;
	std::cin >> N >> D;
	std::vector<int> p(N);
	for (int i = 0; i < N; i++) {
		std::cin >> p[i];
	}
	std::vector<int> q(N);
	for (int i = 0; i < N; i++) {
		std::cin >> q[i];
	}
	cout << solve(N, D, p, q) << endl;
	return 0;
}
