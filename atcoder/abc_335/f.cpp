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

mint solve(int64_t N, std::vector<int64_t> A) {
	mint ans = 0;
	vector<vector<mint>> r(102, vector<mint>(102));
	vector<mint> dp(N + 2);
	dp[1] = 1;
	for (int i = 1; i <= N; ++i) {
		mint x = dp[i];
		for (int j = 1; j <= 100; ++j) {
			x += r[j][i % j];
		}
		ans += x;
		int k = A[i - 1];
		if (k <= 100) {
			r[k][i % k] += x;
		} else {
			for (int j = i + k; j <= N; j += k) {
				dp[j] += x;
			}
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A).val() << endl;
	return 0;
}
