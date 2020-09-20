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

void solve(long long N, std::vector<long long> &x, std::vector<long long> &y) {
	vector<LL> a(N), b(N);
	for (LL i = 0; i < N; ++i) {
		a[i] = x[i] - y[i];
		b[i] = x[i] + y[i];
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	LL ans = max(b.back() - b.front(), a.back() - a.front());
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> x(N);
	std::vector<long long> y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i];
		std::cin >> y[i];
	}
	solve(N, x, y);
	return 0;
}
