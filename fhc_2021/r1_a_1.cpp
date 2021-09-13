// Facebook Hacker Cup 2021 Round 1
// Problem A1: Weak Typing - Chapter 1

#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

const int64_t MOD = 1000000007;

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

int solve1(int N, const string& s) {
	int ans = 0;
	int last_x = -1, last_o = -1;
	for (int i = 0; i < N; ++i) {
		char c = s[i];
		int diff = -1;
		if (c == 'X') {
			ans += last_o > last_x;
			last_x = i;
		} else if (c == 'O') {
			ans += last_x > last_o;
			last_o = i;
		}
	}
	return ans;
}

int solve2(int N, const string &s) {
	modint ans = 0;
	int last_x = -1, last_o = -1;
	for (int i = 0; i < N; ++i) {
		char c = s[i];
		int diff = -1;
		if (c == 'X') {
			if (last_o > last_x) {
				diff = last_o;
			}
			last_x = i;
		} else if (c == 'O') {
			if (last_x > last_o) {
				diff = last_x;
			}
			last_o = i;
		}
		if (diff >= 0) {
			ans += int64_t(diff + 1) * (N - i) % MOD;
		}
	}
	return ans;
}

int main(int argc, char* argv[]) {
	int T, N;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N;
		string s;
		cin >> s;
		cout << "Case #" << t << ": " << solve1(N, s) << endl;
	}
	return 0;
}
