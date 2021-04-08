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

static const long long MOD = 1000000007;

struct modll {
	long long x;
	modll() { }
	modll(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(int y) { return (x + y + MOD) % MOD; }
	modll operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modll operator-(int y) { return (x - y + MOD) % MOD; }
	modll operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modll operator*(int y) { return (x * y) % MOD; }
	modll operator*=(int y) { x = (x * y) % MOD; return *this; }
	modll operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modll operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

int solve(int N, std::string S, std::vector<std::string> &T) {
	vector<modll> dp(S.length() + 1, 0);
	dp[0] = 1;
	for (int i = 1; i <= S.length(); ++i) {
		for (int j = 0; j < (int)T.size(); ++j) {
			if (i >= T[j].length() && S.substr(i - T[j].length(), T[j].length()) == T[j]) {
				dp[i] += dp[i - T[j].length()];
			}
		}
	}
	return dp[S.length()];
}

int main() {
    int N;
	std::string S;
	std::cin >> N >> S;
	std::vector<std::string> T(N);
	for (int i = 0; i < N; i++) {
		std::cin >> T[i];
	}
	cout << solve(N, S, T) << endl;
	return 0;
}
