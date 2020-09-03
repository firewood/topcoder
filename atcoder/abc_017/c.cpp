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

class BIT {
	std::vector<int> bit;
	int size;
public:
	BIT() { }
	BIT(int sz) { init(sz); }
	void init(int sz) {
		bit = std::vector<int>((size = sz) + 1);
	}
	int sum(int i) {
		int s = 0;
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

void solve(long long N, long long M, std::vector<long long> &l, std::vector<long long> &r, std::vector<long long> &s) {
	LL ans = 0;
	BIT lower(M + 1), higher(M + 1);
	for (LL i = 0; i < N; ++i) {
		lower.add(r[i], s[i]);
		higher.add(M + 1 - l[i], s[i]);
	}
	for (LL i = 1; i <= M; ++i) {
		LL a = i > 1 ? lower.sum(i - 1) : 0;
		LL b = i < M ? higher.sum(M - i) : 0;
		ans = max(ans, a + b);
	}
	cout << ans << endl;
}

int main() {
    long long N;
	scanf("%lld", &N);
	long long M;
	scanf("%lld", &M);
	std::vector<long long> l(N);
	std::vector<long long> r(N);
	std::vector<long long> s(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &l[i]);
		scanf("%lld", &r[i]);
		scanf("%lld", &s[i]);
	}
	solve(N, M, l, r, s);
	return 0;
}
