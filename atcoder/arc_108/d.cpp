#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;
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

modll solve(int n, vector<int> v) {
	if (n <= 3) return 1;
	int st = 0;
	for (int i = 0; i < 4; ++i) {
		st |= (1 << i) * v[i];
	}
	switch (st) {
	case 0: case 4: case 8: case 10:case 11: case 12: case 14: case 15:
		return 1;
	case 2: case 3: case 5:case 13:
		return modll::modpow(2, n - 3);
	}
	modll a = 0, b = 1;
	for (int i = 2; i < n; ++i) {
		modll c = a + b;
		a = b;
		b = c;
	}
	return b;

}

int main() {

	int n;
	cin >> n;
	vector<int> v(4);
	for (int i = 0; i < 4; ++i) {
		string s;
		cin >> s;
		v[i] = s[0] - 'A';
	}
	modll ans = solve(n, v);
	cout << ans << endl;
	return 0;
}
