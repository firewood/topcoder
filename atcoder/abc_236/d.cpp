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

vector<int> pc;
map<int, set<int>> memo;
vector<vector<int>> a;
vector<int> used;
int ans = 0;

set<int>& get(int b) {
	set<int>& r = memo[b];
	if (r.empty()) {
		for (int i = 1; i < b; ++i) {
			if ((i | b) == b && pc[i] == 2) {
				int x = *(memo[i].begin());
				for (auto y : get(b^ i)) {
					r.insert(x ^ y);
				}
			}
		}
	}
	return r;
}

void dfs(int x, int remain) {
	if (remain == 0) {
		ans = max(ans, x);
	} else {
		for (int i = 0; i < used.size(); ++i) {
			if (!used[i]) {
				used[i] = 1;
				for (int j = i + 1; j < used.size(); ++j) {
					if (!used[j]) {
						used[j] = 1;
						dfs(x ^ a[i][j], remain - 2);
						used[j] = 0;
					}
				}
				used[i] = 0;
				break;
			}
		}
	}
}

int main() {
	int N;
	cin >> N;
	int N2 = N * 2, bm = 1 << N2;
	a = vector<vector<int>>(N2, vector<int>(N2));
	for (int i = 0; i < N2; ++i) {
		for (int j = i + 1; j < N2; ++j) {
			cin >> a[i][j];
		}
	}
	pc.resize(bm);
	for (int i = 0; i < bm; ++i) {
		pc[i] = popcount(i);
	}
	for (int i = 0; i < N2; ++i) {
		for (int j = i + 1; j < N2; ++j) {
			int b = (1 << i) | (1 << j);
			memo[b].insert(a[i][j]);
		}
	}
#if 1
	used = vector<int>(N2);
	dfs(0, N2);
#else
	if (N <= 4) {
		vector<int> seq(N2);
		iota(seq.begin(), seq.end(), 0);
		do {
			int x = 0;
			for (int i = 0; i < N2; i += 2) {
				x ^= a[min(seq[i], seq[i + 1])][max(seq[i], seq[i + 1])];
			}
			ans = max(ans, x);
		} while (next_permutation(seq.begin(), seq.end()));
	} else {
		const int tcnt = N >= 7 ? 8 : 4;
		for (int i = 0; i < bm / 2; ++i) {
			if (pc[i] == tcnt) {
				const set<int>& p = get(i), & q = get((bm - 1) ^ i);
				for (auto x : p) {
					for (auto y : q) {
						ans = max(ans, x ^ y);
					}
				}
			}
		}
	}
#endif
	cout << ans << endl;
	return 0;
}
