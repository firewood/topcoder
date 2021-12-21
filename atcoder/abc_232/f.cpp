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

static const int64_t INF = 1LL << 60;

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

int64_t solve(int64_t N, int64_t X, int64_t Y, std::vector<int64_t> A, std::vector<int64_t> B) {
    int sz = 1 << N;
    vector<int64_t> dp(sz, INF);
    dp[0] = 0;
    for (int b = 0; b < (sz - 1); ++b) {
        int64_t target = B[popcount(b)], moves = 0;
        for (int i = 0; i < N; ++i) {
            int nb = b | (1 << i);
            if (b != nb) {
                dp[nb] = min(dp[nb], dp[b] + Y * moves + abs(A[i] - target) * X);
                ++moves;
            }
        }
    }
    return dp[sz - 1];
}

int main() {
	int64_t N, X, Y;
	std::cin >> N >> X >> Y;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> B[i];
	}
	cout << solve(N, X, Y, A, B) << endl;
	return 0;
}
