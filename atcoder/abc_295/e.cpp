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

mint solve(int N, int M, int K, std::vector<int> A) {
	mint ans = 0;
	static const size_t COMBSZ = 4004;
	vector<vector<mint>> C(COMBSZ, vector<mint>(COMBSZ));
	for (int i = 0; i < COMBSZ; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	int z = 0;
	sort(A.rbegin(), A.rend());
	while (!A.empty() && A.back() == 0) {
		A.pop_back();
		++z;
	}
	vector<mint> f(M + 1);
	for (int x = 0; x <= M; ++x) {
		int sm = 0;
		for (auto y : A) {
			if (y <= x) {
				++sm;
			}
		}
		for (int i = 0; i <= z; ++i) {
			if (sm + i < K) {
				f[x] += C[z][i] * mint(x).pow(i) * mint(M - x).pow(z - i);
			}
		}
	}
	for (int x = 1; x <= M; ++x) {
		ans += (f[x - 1] - f[x]) * x;
	}
	return ans / mint(M).pow(z);
}

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;
	std::vector<int> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, M, K, A).val() << endl;
	return 0;
}
