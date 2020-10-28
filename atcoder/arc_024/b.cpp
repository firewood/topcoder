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
#include <bitset>

using namespace std;

typedef long long LL;

void solve(long long N, std::vector<int>& color) {
	int prev = -1, cnt = 0, mx = 0;
	for (LL i = 0; i < 2 * N; ++i) {
		int curr = color[i % N];
		if (prev == curr) {
			++cnt;
		} else {
			prev = curr;
			cnt = 1;
		}
		mx = max(mx, cnt);
	}
	int ans = mx > N ? -1 : (mx - 1) / 2 + 1;
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<int> color(N);
	for (int i = 0; i < N; i++) {
		std::cin >> color[i];
	}
	solve(N, color);
	return 0;
}
