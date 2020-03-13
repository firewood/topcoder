// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

const LL MOD = 998244353;

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

template<typename T, size_t SIZE, T DEF_VAL, const T& Compare(const T&, const T&)>
class SegmentTree {
	vector<T> val;
public:
	SegmentTree() : val(SIZE * 2, DEF_VAL) { }
	T get(int a, int b, int l = 0, int r = SIZE, size_t i = 1) {
		if (r <= a || b <= l) return DEF_VAL;
		if (a <= l && r <= b) return val[i];
		return Compare(get(a, b, l, (l + r) / 2, i * 2), get(a, b, (l + r) / 2, r, i * 2 + 1));
	}
	void update(size_t i, T value) {
		i += SIZE;
		val[i] = Compare(val[i], value);
		while (i > 1) i >>= 1, val[i] = Compare(val[i * 2], val[i * 2 + 1]);
	}
};
typedef SegmentTree<long long, 1 << 18, 1LL << 62, min> MinLLSegTree;
typedef SegmentTree<long long, 1 << 18,         0, max> MaxLLSegTree;

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<pair<LL, LL>> xd(n);
		for (int i = 0; i < n; ++i) {
			cin >> xd[i].first >> xd[i].second;
		}
		sort(xd.begin(), xd.end());
		vector<modll> dp(n + 1, 0);
		dp[n] = 1;
		MaxLLSegTree st;
		for (int i = n - 1; i >= 0; --i) {
			int j = (int)(lower_bound(xd.begin() + i + 1, xd.end(), make_pair( xd[i].first + xd[i].second, 0LL )) - xd.begin());
			LL m = max((LL)i, st.get(i, j));
			st.update(i, m);
			dp[i] = dp[i + 1] + dp[m + 1];
		}
		cout << dp[0] << endl;
	}
	return 0;
}
