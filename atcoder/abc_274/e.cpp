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

#ifdef _MSC_VER
#define popcount __popcnt
#else
#define popcount __builtin_popcount
#endif

typedef long double LD;

LD solve(int64_t N, int64_t M, std::vector<int64_t> X, std::vector<int64_t> Y, std::vector<int64_t> P, std::vector<int64_t> Q) {
	LD ans = 1e10;
	const int bsz = 1 << (N + M), full = (1 << N) - 1;
	vector<vector<LD>> dp(bsz, vector<LD>(N + M, 1e10));
	auto get_x = [&](int index) -> LD {
		return index < 0 ? 0.0 : ((index < N) ? X[index] : P[index - N]);
	};
	auto get_y = [&](int index) -> LD {
		return index < 0 ? 0.0 : ((index < N) ? Y[index] : Q[index - N]);
	};
	auto get_speed = [&](int b) -> LD {
		return LD(1LL << popcount(b >> N));
	};
	auto get_time = [&](int from, int to, int flags) -> LD {
		const LD dx = get_x(to) - get_x(from), dy = get_y(to) - get_y(from);
		return sqrt(dx * dx + dy * dy) / get_speed(flags);
	};
	for (int to = 0; to < N + M; ++to) {
		dp[1LL << to][to] = get_time(-1, to, 0);
	}
	for (int b = 1; b < bsz; ++b) {
		const LD speed = get_speed(b);
		for (int from = 0; from < N + M; ++from) {
			for (int to = 0; to < N + M; ++to) {
				if ((b & (1 << to)) == 0) {
					dp[b | (1 << to)][to] = min(dp[b | (1 << to)][to], dp[b][from] + get_time(from, to, b));
				}
			}
			if ((b & full) == full) {
				ans = min(ans, dp[b][from] + get_time(from, -1, b));
			}
		}
	}
	return ans;
}

int main() {
	cout.precision(10);
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}
	std::vector<int64_t> P(M), Q(M);
	for (int i = 0; i < M; i++) {
		std::cin >> P[i] >> Q[i];
	}
	cout << solve(N, M, X, Y, P, Q) << endl;
	return 0;
}
