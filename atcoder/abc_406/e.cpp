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
#include <atcoder/modint>

using namespace std;

using mint = atcoder::modint998244353;

#ifdef _MSC_VER
#define popcount __popcnt64
#else
#define popcount __builtin_popcountll
#endif

mint calc(int64_t N, int K) {
	mint ans = 0;

	// 桁DP N未満の個数と総和
	vector<vector<mint>> cnt(64, vector<mint>(64)), sum(64, vector<mint>(64));
	int bc = 0;
	mint m = 0;
	for (int i = 0; i < 60; ++i) {
		int64_t b = 1LL << (59 - i);
		for (int j = 0; j < 60; ++j) {
			cnt[i + 1][j + 1] += cnt[i][j];
			cnt[i + 1][j + 1] += cnt[i][j + 1];
			sum[i + 1][j + 1] += sum[i][j] + cnt[i][j] * b;
			sum[i + 1][j + 1] += sum[i][j + 1];
		}
		if (N & b) {
			// このbitまでは1でこのbitが0
			cnt[i + 1][bc + 1] += 1;
			sum[i + 1][bc + 1] += m;
			++bc;
			m += b;
		}
	}

	ans = sum[60][K + 1];
	if (popcount(N) == K) {
		ans += N;
	}

	return ans;
}

int main() {
	int64_t T, N, K;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		mint ans = 0;
		cin >> N >> K;
		ans = calc(N, K);
		cout << ans.val() << endl;
	}
	return 0;
}
