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

static const int INF = 1 << 30;

void solve(int N, std::vector<int> &c) {
	vector<int> dp(N, INF);
	int ans = N;
	for (int i = 0; i < N; ++i) {
		int pos = upper_bound(dp.begin(), dp.end(), c[i]) - dp.begin();
		dp[pos] = c[i];
		ans = min(ans, N - pos - 1);
	}
	cout << ans << endl;
}

int main() {
    int N;
	std::cin >> N;
	std::vector<int> c(N);
	for (int i = 0; i < N; i++) {
		std::cin >> c[i];
		--c[i];
	}
	solve(N, c);
	return 0;
}
