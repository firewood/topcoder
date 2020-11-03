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
static const LL INF = 1LL << 60;
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

void solve(long long N, long long a, long long b, long long M, std::vector<long long> &x, std::vector<long long> &y) {
	modll ans = 0;
	vector<set<LL>> edge(N);
	for (LL i = 0; i < M; ++i) {
		edge[x[i]].emplace(y[i]);
		edge[y[i]].emplace(x[i]);
	}
	vector<modll> cnt(N, 0);
	cnt[a] = 1;
	vector<LL> q(1, a);
	while (!q.empty()) {
		vector<LL> nq;
		for (auto from : q) {
			for (auto to : edge[from]) {
				if (!cnt[to]) {
					for (auto from : q) {
						if (edge[to].find(from) != edge[to].end()) {
							cnt[to] += cnt[from];
						}
					}
					nq.emplace_back(to);
				}
			}
		}
		q = nq;
	}
	cout << cnt[b] << endl;
}

int main() {
	long long N, a, b, M;
	std::cin >> N >> a >> b >> M;
	--a, --b;
	std::vector<long long> x(M);
	std::vector<long long> y(M);
	for (int i = 0; i < M; i++) {
		std::cin >> x[i] >> y[i];
		x[i]--, y[i]--;
	}
	solve(N, a, b, M, x, y);
	return 0;
}
