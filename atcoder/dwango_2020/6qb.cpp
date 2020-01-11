// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll& r) { return (x + r.x) % MOD; }
	modll operator+=(const modll& r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll& r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll& r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll& r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll& r) { return x = (x * r.x) % MOD; }
	static modll modinv(int a) { return modpow(a, MOD - 2); }
	static modll modpow(int a, int b) {
		modll x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<int> x(n);
		for (int i = 0; i < n; ++i) {
			cin >> x[i];
		}
		modll fact = 1, prev = 0, ans = 0;
		for (int i = 1; i < n; ++i) {
			fact *= i;
		}
		for (int i = 0; i < n - 1; ++i) {
			prev += fact * modll::modinv(i + 1);
			ans += prev * (x[i + 1] - x[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
