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

mint solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> B) {
	vector<vector<mint>> C(1024, vector<mint>(1024, 0));
	for (int i = 0; i < 1024; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
		}
	}
	int connected[512][512];
	for (int i = 0; i < M; ++i) {
		connected[A[i]][B[i]] = connected[B[i]][A[i]] = true;
	}
	vector<vector<mint>> dp(512, vector<mint>(512, 0));
	for (int i = 0; i <= 2 * N; ++i) {
		dp[i][0] = 1;
	}
	for (int j = 1; j <= N; j++) {
		for (int i = 0; i <= 2 * (N - j); ++i) {
			for (int k = 1; k <= j; ++k) {
				dp[i][j] += (dp[i + 1][k - 1] * dp[i + 2 * k][j - k] * C[j][k]) * connected[i][i + 2 * k - 1];
			}
		}
	}
	return dp[0][N];
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i]; --B[i];
	}
	cout << solve(N, M, A, B).val() << endl;
	return 0;
}
