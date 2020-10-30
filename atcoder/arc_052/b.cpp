#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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
typedef long double LD;

void solve(long long N, long long Q, std::vector<long long> &X, std::vector<long long> &R, std::vector<long long> &H, std::vector<long long> &A, std::vector<long long> &B) {
	vector<LD> sum(20002);
	for (int i = 0; i < N; ++i) {
		LD prev = 0;
		for (int j = 0; j <= H[i]; ++j) {
			LD r = (LD)R[i] * j / H[i];
			LD next = r * r * M_PI * j / 3.0;
			sum[X[i] + H[i] - j + 1] += next - prev;
			prev = next;
		}
	}
	for (int i = 1; i <= 20000; ++i) {
		sum[i + 1] += sum[i];
	}
	for (int i = 0; i < Q; ++i) {
		LD ans = sum[B[i]] - sum[A[i]];
		cout << ans << endl;
	}
}

int main() {
	cout.precision(10);
	long long N, Q;
	std::cin >> N >> Q;
	std::vector<long long> X(N), R(N), H(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> R[i] >> H[i];
	}
	std::vector<long long> A(Q), B(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> A[i] >> B[i];
	}
	solve(N, Q, X, R, H, A, B);
	return 0;
}
