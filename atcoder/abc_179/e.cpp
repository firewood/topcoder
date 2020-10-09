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

void solve(long long N, long long X, long long M) {
	LL ans = 0;
	LL x = X;
	vector<LL> prev(M + 1, -1), sum(M + 1);
	LL i;
	for (i = 0; i < min(N, 10000LL); ++i) {
		ans += x;
		x = x * x % M;
	}
	for (; i < N; ++i) {
		ans += x;
		x = x * x % M;
		if (prev[x] >= 0) {
			LL t = i - prev[x];
			LL r = (N - i - t) / t;
			LL diff = ans - sum[x];
			if (r > 0) {
				ans += diff * r;
				i += t * r;
			}
		}
		sum[x] = ans;
		prev[x] = i;
	}
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	long long X;
	std::cin >> X;
	long long M;
	std::cin >> M;
	solve(N, X, M);
	return 0;
}
