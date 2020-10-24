#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

void solve(long long N) {
	map<LL, LL> sa;
	for (LL f = 1, t = 3; t <= 1e18; ++f, t *= 3) {
		sa[t] = f;
	}
	for (LL f = 1, t = 5; t <= 1e18; ++f, t *= 5) {
		if (sa.find(N - t) != sa.end()) {
			cout << sa[N - t] << " " << f << endl;
			return;
		}
	}
	cout << -1 << endl;
}

int main() {
    long long N;
	std::cin >> N;
	solve(N);
	return 0;
}
