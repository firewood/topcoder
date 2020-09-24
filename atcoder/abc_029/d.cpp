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

static const LL DIV = 100000;

inline LL calc(LL x) {
	LL a = 0;
	for (; x > 0; x /= 10) {
		a += (x % 10) == 1;
	}
	return a;
}

void solve(long long N) {
	LL ans = 0, i;
	for (i = 0; i < min(N, DIV); ++i) {
		ans += calc(i);
	}
	LL base = ans;
	for (; i <= N - DIV; i += DIV) {
		ans += base + calc(i / DIV) * DIV;
	}
	for (; i <= N; ++i) {
		ans += calc(i);
	}
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	solve(N);
	return 0;
}
