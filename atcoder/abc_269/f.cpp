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

mint calc_seq(mint a, mint d, mint n) {
	return (2 * a + (n - 1) * d) * n * div2;
}

mint calc(int N, int M, int A, int B) {
	mint n = (B + 1) / 2;
	mint a = calc_seq(calc_seq(1, 2, n), 2 * n * M, (A + 1) / 2);
	n = B / 2;
	mint b = calc_seq(calc_seq(M + 2, 2, n), 2 * n * M, A / 2);
	return a + b;
}

mint calc2(int N, int M, int A, int B, int C, int D) {
	mint r = 0;
	for (int i = A; i <= B; ++i) {
		for (int j = C; j <= D; ++j) {
			mint seq = i - 1;
			seq *= M;
			seq += j;
			if (((i + j) % 2) == 0) {
				r += seq;
			}
		}
	}
	return r;
}

void solve(int64_t N, int64_t M, int64_t Q, std::vector<int64_t> A, std::vector<int64_t> B, std::vector<int64_t> C, std::vector<int64_t> D) {
	for (int i = 0; i < Q; ++i) {
		int a = A[i], b = B[i], c = C[i], d = D[i];
		mint ans = calc(N, M, b, d) - calc(N, M, a - 1, d) - calc(N, M, b, c - 1) + calc(N, M, a - 1, c - 1);
		cout << ans.val() << endl;
	}
}

void solve2(int64_t N, int64_t M, int64_t Q, std::vector<int64_t> A, std::vector<int64_t> B, std::vector<int64_t> C, std::vector<int64_t> D) {
	for (int i = 0; i < Q; ++i) {
		int a = A[i], b = B[i], c = C[i], d = D[i];
		mint ans = calc2(N, M, a, b, c, d);
		cout << ans.val() << endl;
	}
}

int main() {
	int64_t N, M, Q;
	std::cin >> N >> M >> Q;
	std::vector<int64_t> A(Q), B(Q), C(Q), D(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	solve(N, M, Q, A, B, C, D);
#ifdef _DEBUG
	solve2(N, M, Q, A, B, C, D);
#endif
	return 0;
}
