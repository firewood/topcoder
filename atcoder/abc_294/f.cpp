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

LD solve(int64_t N, int64_t M, int64_t K, std::vector<int> A, std::vector<int> B, std::vector<int> C, std::vector<int> D) {
	auto count = [&](LD x) -> int64_t {
		int64_t sum = 0;
		LD y = x / (1 - x);
		vector<LD> v(N);
		for (int64_t i = 0; i < N; ++i) {
			v[i] = LD(A[i]) - B[i] * y;
		}
		sort(v.begin(), v.end());
		for (int64_t i = 0; i < M; ++i) {
			LD w = LD(C[i]) - D[i] * y;
			sum += N - (lower_bound(v.begin(), v.end(), -w) - v.begin());
		}
		return sum;
	};
	LD left = 0, right = 1;
	for (int64_t i = 0; i < 100; ++i) {
		LD mid = (left + right) / 2;
		int64_t c = count(mid);
		if (c <= K) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return left;
}

int main() {
	cout.precision(20);
	int64_t N, M, K;
	std::cin >> N >> M >> K;
	--K;
	std::vector<int> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	std::vector<int> C(M), D(M);
	for (int i = 0; i < M; i++) {
		std::cin >> C[i] >> D[i];
	}
	cout << solve(N, M, K, A, B, C, D) * 100.0 << endl;
	return 0;
}
