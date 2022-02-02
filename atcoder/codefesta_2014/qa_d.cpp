#include <algorithm>
#include <cctype>
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

#ifdef __GNUC__
#define popcount __builtin_popcount
#elif _MSC_VER >= 1400
#include <intrin.h>
#define popcount __popcnt
#else
static inline int popcount(unsigned int b) {
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	return (b + (b >> 16)) & 0x3F;
}
#endif

typedef pair<int64_t, int64_t> II;

static const int64_t INF = 1LL << 60;

int64_t ans = INF;

void dfs(int64_t x, int64_t d, int64_t A, int b) {
	if (d <= 0) {
		ans = min(ans, abs(A - x));
		return;
	}
#if 0
	vector<II> a;
	for (int i = 0; i < 10; ++i) {
		if (b & (1 << i)) {
			int64_t next = x + d * i;
			a.emplace_back(II(abs(A - next), next));
		}
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < min(2, int(a.size())); ++i) {
		dfs(a[i].second, d / 10, A, b);
	}
#else
	int64_t p = -1, q = -1, pd = INF, qd = INF;
	for (int i = 0; i < 10; ++i) {
		if (b & (1 << i)) {
			int64_t next = x + d * i, diff = abs(next - A);
			if (diff < pd) {
				q = p;
				qd = pd;
				p = next;
				pd = diff;
			} else if (diff < qd) {
				q = next;
				qd = diff;
			}
		}
	}
	dfs(p, d / 10, A, b);
	if (q >= 0) {
		dfs(q, d / 10, A, b);
	}
#endif
}

int64_t solve(int64_t A, int64_t K) {
	int64_t d = 1;
	while (d <= A) {
		d *= 10;
	}
	d /= 10;
	for (int b = 1; b < (1 << 10); ++b) {
		if (popcount(b) != K) continue;
		dfs(0, d, A, b);
		dfs(0, d / 10, A, b);
	}
	return ans;
}

int main() {
	int64_t A, K;
	std::cin >> A >> K;
	cout << solve(A, K) << endl;
	return 0;
}
