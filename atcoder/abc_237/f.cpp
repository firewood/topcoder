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
	static modint permutation(int n, int r);
	static modint combination(int n, int r);
	static modint nHr(int n, int r);
};

int get_lis(const vector<int>& a) {
	size_t N = a.size();
	vector<int> c(N, 1 << 30);
	for (int i = 0; i < N; ++i) {
		*lower_bound(c.begin(), c.end(), a[i]) = a[i];
	}
	return int(lower_bound(c.begin(), c.end(), 1 << 30) - c.begin());
}

int64_t solve2(int64_t N, int64_t M) {
	modint ans = 0;
	vector<int> seq(N, 1);
	while (true) {
		if (get_lis(seq) == 3) {
			ans += 1;
		}
		int i;
		for (i = 0; i < N; ++i) {
			seq[i] += 1;
			if (seq[i] > M) {
				seq[i] = 1;
			} else {
				break;
			}
		}
		if (i >= N) {
			break;
		}
	}
	return ans;
}

modint solve(int64_t N, int64_t M) {
	modint ans = 0;
	vector<vector<vector<modint>>> dp(M + 1, vector<vector<modint>>(M + 1, vector<modint>(M + 1, 0)));
	dp[M][M][M] = 1;
	for (int t = 0; t < N; ++t) {
		vector<vector<vector<modint>>> next(M + 1, vector<vector<modint>>(M + 1, vector<modint>(M + 1, 0)));
		for (int i = 0; i <= M; ++i) {
			for (int j = 0; j <= M; ++j) {
				for (int k = 0; k <= M; ++k) {
					for (int x = 0; x < M; ++x) {
						if (x <= i) {
							next[x][j][k] += dp[i][j][k];
						} else if (x <= j) {
							next[i][x][k] += dp[i][j][k];
						} else if (x <= k) {
							next[i][j][x] += dp[i][j][k];
						}
					}
				}
			}
		}
		dp = next;
	}
	for (int i = 0; i < M; ++i) {
		for (int j = i + 1; j < M; ++j) {
			for (int k = j + 1; k < M; ++k) {
				ans += dp[i][j][k];
			}
		}
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	cout << solve(N, M) << endl;
	return 0;
}
