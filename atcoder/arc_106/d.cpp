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
const mint div2 = mint(2).inv();

vector<mint> solve(int64_t N, int64_t K, std::vector<int64_t> A) {
	static const int COMBSZ = 5002;
	vector<vector<mint>> C(COMBSZ, vector<mint>(COMBSZ, 0));
	for (int i = 0; i < COMBSZ; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
		}
	}

	vector<mint> ans(K), pow_sum(K + 1);
	for (int i = 0; i < N; ++i) {
		mint x = 1;
		for (int j = 0; j <= K; ++j) {
			pow_sum[j] += x;
			x *= A[i];
		}
	}

	mint mul = 1;
	for (int x = 1; x <= K; ++x) {
		mint& val = ans[x - 1];
		for (int i = 0; i <= x; ++i) {
			val += C[x][i] * pow_sum[i] * pow_sum[x - i];
		}
		mul *= 2;
		val = (val - mul * pow_sum[x]) * div2;
	}

	return ans;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	vector<mint> ans = solve(N, K, A);
	for (auto x : ans) {
		cout << x.val() << endl;
	}
	return 0;
}
