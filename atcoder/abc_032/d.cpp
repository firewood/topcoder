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

typedef long long LL;

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

LL solve(long long N, long long W, std::vector<long long> &v, std::vector<long long> &w) {
	LL ans = 0;
    if (N <= 30) {
        LL p = N / 2, q = N - p;
        vector<LL> vsum(1 << p), wsum(1 << p);
        for (LL b = 1; b < (1 << p); ++b) {
            LL &vv = vsum[b], &ww = wsum[b];
            for (LL i = 0; i < p; ++i) {
                if (b & (1 << i)) {
                    vv += v[i]; ww += w[i];
                }
            }
        }
        for (LL b = 0; b < (1 << q); ++b) {
            LL vv = 0, ww = 0;
            for (LL i = 0; i < q; ++i) {
                if (b & (1 << i)) {
                    vv += v[p + i]; ww += w[p + i];
                }
            }
            if (ww > W) continue;
            for (LL i = 0; i < (1 << p); ++i) {
                if (ww + wsum[i] <= W) {
                    ans = max(ans, vv + vsum[i]);
                }
            }
        }
    } else if (*max_element(w.begin(), w.end()) <= 1000) {
        vector<LL> dp(1000 * N + 1);
        for (LL i = 0; i < N; ++i) {
            vector<LL> next = dp;
            for (LL j = 0; j + w[i] <= W; ++j) {
                next[j + w[i]] = max(next[j + w[i]], dp[j] + v[i]);
            }
            dp = next;
        }
        ans = *max_element(dp.begin(), dp.end());
    } else {
        vector<LL> dp(1000 * N + 1, 1LL << 60);
        dp[0] = 0;
        for (LL i = 0; i < N; ++i) {
            vector<LL> next = dp;
            for (LL j = dp.size() - 1; j >= v[i]; --j) {
                next[j] = min(next[j], dp[j - v[i]] + w[i]);
            }
            dp = next;
        }
        for (LL i = 0; i < dp.size(); ++i) {
            if (dp[i] <= W) ans = i;
        }
    }
    return ans;
}

int main() {
#if DEBUG
    freopen("in_4.txt", "r", stdin);
#endif

    long long N;
    std::cin >> N;
    long long W;
    std::cin >> W;
    std::vector<long long> v(N);
    std::vector<long long> w(N);
    for (int i = 0; i < N; i++) {
        std::cin >> v[i]; // v[i]--;
        std::cin >> w[i]; // w[i]--;
    }
    cout << solve(N, W, v, w) << endl;
	return 0;
}
