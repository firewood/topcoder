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

void solve(long long N, std::vector<long long> &D) {
	bool f = false;
	sort(D.begin(), D.end());
	int used[24] = { 1 };
	int ans = 24;
	for (int t : D) {
		f = !f;
		int i = f ? t : ((24 - t) % 24);
		if (++used[i] >= 2) {
			ans = 0;
		}
	}
	for (int i = 0; i < 24; ++i) {
		for (int j = i + 1; j < 24; ++j) {
			if (used[i] && used[j]) {
				ans = min(ans, j - i);
			}
		}
	}
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> D(N);
	for (int i = 0; i < N; i++) {
		std::cin >> D[i];
	}
	solve(N, D);
	return 0;
}
