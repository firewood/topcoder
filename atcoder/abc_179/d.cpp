#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

typedef long long LL;
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LL, II> III;
typedef priority_queue<III, vector<III>, greater<>> Queue;
static const LL INF = 1LL << 60;

static const long long MOD = 998244353;
static const size_t MAX_N = 1000001;

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

class MODBIT {
	std::vector<modll> bit;
	int size;
public:
	MODBIT() { }
	MODBIT(int sz) { init(sz); }
	void init(int sz) {
		bit = std::vector<modll>((size = sz) + 1, 0);
	}
	int sum(int i) {
		modll s = 0;
		while (i > 0) {
			s += bit[i];
			i -= i & -i;
		}
		return s;
	}
	void add(int i, int x) {
		while (i <= size) {
			bit[i] += x;
			i += i & -i;
		}
	}
};

void solve(int N, int K, std::vector<int>& L, std::vector<int>& R) {
	MODBIT bit(200001);
	bit.add(1, 1);
	bit.add(2, -1);
	for (int i = 1; i < N; ++i) {
		int r = N - i;
		modll curr = bit.sum(i);
		for (LL j = 0; j < K; ++j) {
			if (L[j] > r) continue;
			bit.add(i + L[j], curr);
			bit.add(i + min(R[j], r) + 1, -curr);
		}
	}
	modll ans = bit.sum(N);
	cout << ans << endl;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<int> L(K), R(K);
	for (int i = 0; i < K; i++) {
		std::cin >> L[i] >> R[i];
	}
	solve(N, K, L, R);
	return 0;
}
