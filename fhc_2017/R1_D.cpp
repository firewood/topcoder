//
// Facebook Hacker Cup 2017 Round 1
// D. Beach Umbrellas
//

/*
Constraints

1 <= T <= 100

*/

#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

static const LL MOD = 1000000007LL;

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

int factorial[2001] = { 1 };
map<II, int> ncr_memo;

int nCr(int n, int r) {
	if (n < r) {
		return 0;
	}
	r = min(r, n - r);
	if (r == 0) {
		return 1;
	}

	II key(n, r);
	int &ncr = ncr_memo[key];
	if (ncr == 0) {
		modll res = 1;
		for (int i = 0; i < r; ++i) {
			res *= (n - i);
		}
		res *= modll::modinv(factorial[r]);
		ncr = res;
	}
	return ncr;
}

int nHr(int n, int r) {
	return nCr(n + r - 1, r);
}

int solve(int N, int M, vector<int> &R) {
	if (N <= 1) {
		return M;
	}
	modll ans = 0;
	int sum = accumulate(R.begin(), R.end(), 0);
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int remain = M - 1 - sum * 2 + R[i] + R[j];
			if (remain >= 0) {
				ans += nHr(N + 1, remain);
			}
		}
	}
	ans *= 2;
	ans *= factorial[N - 2];
	return ans;
}

int main(int argc, char *argv[])
{
	modll f = 1;
	for (int i = 1; i <= 2000; ++i) {
		f *= i;
		factorial[i] = f;
	}

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, M;
		cin >> N >> M;
		vector<int> R(N);
		for (int i = 0; i < N; ++i) {
			cin >> R[i];
		}
		int ans = solve(N, M, R);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
