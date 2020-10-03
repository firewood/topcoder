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

void solve(long long N, std::vector<long long> &a) {
	LL ans = 0;
	for (LL i = 0; i < N; ++i) {
		LL x = max(0LL, a[i] / (N + 1) - N);
		a[i] -= x * (N + 1);
		ans += x * (N + 1);
	}
	int index;
	while (index = max_element(a.begin(), a.end()) - a.begin(), a[index] >= N) {
		++ans;
		for (LL i = 0; i < N; ++i) {
			a[i] += i == index ? -N : 1;
		}
	}
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	solve(N, a);
	return 0;
}
