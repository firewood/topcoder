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

typedef pair<int64_t, int64_t> II;
template <typename T> inline pair<T, T> operator+(const pair<T, T>& a, const pair<T, T>& b) { return make_pair(a.first + b.first, a.second + b.second); }
template <typename T> inline pair<T, T> operator-(const pair<T, T>& a, const pair<T, T>& b) { return make_pair(a.first - b.first, a.second - b.second); }
template <typename T> inline pair<T, T> operator*(const pair<T, T>& a, T c) { return make_pair(a.first * c, a.second * c); }
template <typename T> inline pair<T, T> operator*(T c, const pair<T, T>& a) { return make_pair(a.first * c, a.second * c); }
template <typename T> inline pair<T, T> operator/(const pair<T, T>& a, T c) { return make_pair(a.first / c, a.second / c); }

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

int64_t solve(int64_t N, int64_t M, int64_t A, int64_t B, int64_t C, int64_t D, int64_t E, int64_t F, std::vector<int64_t> X, std::vector<int64_t> Y) {
	II va(A, B), vb(C, D), vc(E, F);
	set<II> s;
	for (int i = 0; i < M; ++i) {
		s.insert(II(X[i], Y[i]));
	}
	vector<vector<modint>> dp(N + 1, vector<modint>(N + 1, 0));
	dp[0][0] = 1;
	for (int64_t i = 0; i < N; ++i) {
		vector<vector<modint>> next(N + 1, vector<modint>(N + 1, 0));
		for (int64_t a = 0; a <= i; ++a) {
			for (int64_t b = 0; a + b <= i; ++b) {
				int64_t c = i - a - b;
				II v = a * va + b * vb + c * vc;
				if (s.find(v + va) == s.end()) {
					next[a + 1][b] += dp[a][b];
				}
				if (s.find(v + vb) == s.end()) {
					next[a][b + 1] += dp[a][b];
				}
				if (s.find(v + vc) == s.end()) {
					next[a][b] += dp[a][b];
				}
			}
		}
		dp = next;
	}
	modint ans = 0;
	for (int a = 0; a <= N; ++a) {
		ans += accumulate(dp[a].begin(), dp[a].end(), modint(0));
	}
	return ans;
}

int main() {
	II a(3, 5), b(1, 1);
	II c = a - b;



	int64_t N, M, A, B, C, D, E, F;
	std::cin >> N >> M >> A >> B >> C >> D >> E >> F;
	std::vector<int64_t> X(M), Y(M);
	for (int i = 0; i < M; i++) {
		std::cin >> X[i] >> Y[i];
	}
	cout << solve(N, M, A, B, C, D, E, F, X, Y) << endl;
	return 0;
}
