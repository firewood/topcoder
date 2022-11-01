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

mint solve(int N, int M, int K) {
	mint r = mint(M).inv(), ans = 0;
	vector<mint> dp(N + 1);
	dp[0] = 1;
	for (int k = 0; k < K; ++k) {
		vector<mint> next(N + 1);
		for (int j = 0; j < N; ++j) {
			for (int m = 1; m <= M; ++m) {
				int nx = j + m;
				if (nx > N) {
					nx = N - (nx - N);
				}
				next[nx] += dp[j] * r;
			}
		}
		dp = next;
		ans += dp[N];
	}
	return ans;
}

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;
	cout << solve(N, M, K).val() << endl;
	return 0;
}
