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

LL solve(long long N, long long M, std::vector<long long>& A, std::vector<long long>& B, long long K, std::vector<long long>& C, std::vector<long long>& D) {
	LL ans = 0;
	for (LL b = 0; b < (1 << K); ++b) {
		vector<LL> c(N);
		for (LL i = 0; i < K; ++i) {
			if (b & (1 << i)) {
				c[C[i]] += 1;
			} else {
				c[D[i]] += 1;
			}
		}
		LL x = 0;
		for (int i = 0; i < M; i++) {
			x += c[A[i]] && c[B[i]];
		}
		ans = max(ans, x);
	}
	return ans;
}

int main() {
	long long N, M, K;
	std::cin >> N >> M;
	std::vector<long long> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i];
		--B[i];
	}
	std::cin >> K;
	std::vector<long long> C(K), D(K);
	for (int i = 0; i < K; i++) {
		std::cin >> C[i] >> D[i];
		--C[i];
		--D[i];
	}
	cout << solve(N, M, A, B, K, C, D) << endl;
	return 0;
}
