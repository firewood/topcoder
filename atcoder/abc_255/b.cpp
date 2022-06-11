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

typedef long double LD;

LD solve(int64_t N, int64_t K, std::vector<int64_t> A, std::vector<int64_t> X, std::vector<int64_t> Y) {
	LD ans = 0;
	for (int i = 0; i < N; ++i) {
		LD mn = 1e20;
		for (int j = 0; j < K; ++j) {
			LD dx = X[A[j]] - X[i], dy = Y[A[j]] - Y[i];
			mn = min(mn, dx * dx + dy * dy);
		}
		ans = max(ans, mn);
	}
	return sqrt(ans);
}

int main() {
	cout.precision(20);
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> A(K);
	for (int i = 0; i < K; i++) {
		std::cin >> A[i];
		--A[i];
	}
	std::vector<int64_t> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}
	cout << solve(N, K, A, X, Y) << endl;
	return 0;
}
