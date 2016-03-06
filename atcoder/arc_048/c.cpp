// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

static const int MOD = 1000000007;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

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
};

modll calc(int bits) {
	int b = 1;
	modll a = 2, r = 1;
	while (bits > 0) {
		if (bits & b) {
			bits -= b;
			r *= a;
		}
		a *= a;
		b *= 2;
	}
	return r;
}

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	vector<int> v;
	set<int> s;
	int g = -1;
	for (int i = 0; i < N; ++i) {
		int L;
		cin >> L;
		v.push_back(L);
		if (g < 0) {
			g = L;
		} else {
			g = gcd(g, L);
		}
		s.insert(L);
	}
	sort(v.begin(), v.end());
	modll ans = calc(v[0]);
	switch (s.size()) {
	case 1:
		break;
	case 2:
		ans *= calc((*v.rbegin() - *v.begin()) / 2);
		break;
	default:
		ans *= calc(max(1, g / 2));
		break;
	}
	cout << ans << endl;
	return 0;
}
