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

void solve(int N, std::vector<int64_t> &C, std::vector<int64_t> &P, int Q, std::vector<int64_t> &L, std::vector<int64_t> &R) {
	vector<vector<int64_t>> sum(2, vector<int64_t>(N + 1));
	for (int i = 0; i < N; ++i) {
		sum[0][i + 1] = sum[0][i];
		sum[1][i + 1] = sum[1][i];
		sum[C[i]][i + 1] += P[i];
	}
	for (int i = 0; i < Q; ++i) {
		cout << sum[0][R[i]] - sum[0][L[i] - 1] << " " << sum[1][R[i]] - sum[1][L[i] - 1] << endl;
	}
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif
	int N, Q;
	std::cin >> N;
	std::vector<int64_t> C(N), P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> C[i] >> P[i];
        --C[i];
	}
	std::cin >> Q;
	std::vector<int64_t> L(Q), R(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> L[i] >> R[i];
	}
    solve(N, C, P, Q, L, R);
	return 0;
}
