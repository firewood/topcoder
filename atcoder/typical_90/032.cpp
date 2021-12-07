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

int64_t solve(int64_t N, std::vector<std::vector<int64_t>> A, int64_t M, std::vector<int64_t> X, std::vector<int64_t> Y) {
	int64_t ans = INF;
	vector<vector<int64_t>> ng(N, vector<int64_t>(N));
	for (int i = 0; i < M; ++i) {
		ng[X[i]][Y[i]] = 1;
		ng[Y[i]][X[i]] = 1;
	}
	vector<int> seq(N);
	iota(seq.begin(), seq.end(), 0);
	do {
		int64_t sum = 0;
		for (int i = 0; i < N; ++i) {
			sum += A[seq[i]][i];
			if (i > 0 && ng[seq[i - 1]][seq[i]]) {
				sum = INF;
				break;
			}
		}
		ans = min(ans, sum);
	} while (next_permutation(seq.begin(), seq.end()));
	return ans < INF ? ans : -1;
}

int main() {
	int64_t N, M;
	std::cin >> N;
	std::vector<std::vector<int64_t>> A(N, std::vector<int64_t>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> A[i][j];
		}
	}
	std::cin >> M;
	std::vector<int64_t> X(M), Y(M);
	for (int i = 0; i < M; i++) {
		std::cin >> X[i] >> Y[i];
		--X[i], --Y[i];
	}
	cout << solve(N, A, M, X, Y) << endl;
	return 0;
}
