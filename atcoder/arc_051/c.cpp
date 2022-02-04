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

static const int64_t MOD = 1000000007;

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

void solve(int64_t N, int64_t A, int64_t B, std::vector<int64_t> a) {
	priority_queue<II, vector<II>, greater<>> q;
	sort(a.begin(), a.end());
	for (int i = 0; i < N; ++i) {
		q.emplace(II(a[i], i));
	}
	int64_t r = A > 1 ? B : 0;
	while (r > 0) {
		--r;
		II top = q.top();
		q.pop();
		q.emplace(II(top.first * A, top.second));
		if (top.second == N - 1) {
			break;
		}
	}
	int64_t x = r / N;
	modint y = modint::modpow(int(A), int(x % (MOD - 1)));
	vector<modint> b;
	while (!q.empty()) {
		b.emplace_back(modint(q.top().first % MOD) * y);
		q.pop();
	}
	r -= x * N;
	for (int i = 0; i < r; ++i) {
		b[i] *= int(A);
	}
	for (int i = 0; i < N; ++i) {
		cout << b[(i + r) % N] << endl;
	}
}

int main() {
	int64_t N, A, B;
	std::cin >> N >> A >> B;
	std::vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	solve(N, A, B, a);
	return 0;
}
