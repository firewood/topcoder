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

int64_t solve(int N, int M, std::vector<int64_t> X, std::vector<int64_t> Y, std::vector<int64_t> Z) {
	int64_t ans = 0;
	vector<vector<int>> constraints(19);
	vector<int64_t> dp(1 << N);
	for (int i = 0; i < M; ++i) {
		constraints[X[i]].emplace_back(i);
	}
	auto check = [&](int b) {
		for (int i : constraints[popcount(b)]) {
			int cnt = 0;
			for (int j = 0; j < N; ++j) {
				cnt += ((b & (1 << j)) != 0) && (j + 1) <= Y[i];
			}
			if (cnt > Z[i]) {
				return false;
			}
		}
		return true;
	};
	dp[0] = 1;
	for (int b = 0; b < (1 << N); ++b) {
		for (int i = 0; i < N; ++i) {
			int next = b | (1 << i);
			if (b != next && check(next)) {
				dp[next] += dp[b];
			}
		}
	}
	return dp.back();
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int64_t> X(M), Y(M), Z(M);
	for (int i = 0; i < M; i++) {
		std::cin >> X[i] >> Y[i] >> Z[i];
	}
	cout << solve(N, M, X, Y, Z) << endl;
	return 0;
}
