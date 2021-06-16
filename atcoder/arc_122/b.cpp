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

LD solve(int64_t N, std::vector<int64_t> A) {
	LD left = 0, right = 1e12;
	auto calc = [&](LD t) -> LD {
		LD sum = 0;
		for (int i = 0; i < N; ++i) {
			sum += A[i] - min(LD(A[i]), 2 * t);
		}
		return t + sum / N;
	};
	for (int t = 0; t < 100; ++t) {
		if (calc((left * 2 + right) / 3) < calc((left + right * 2) / 3)) {
			right = (left + right * 2) / 3;
		} else {
			left = (left * 2 + right) / 3;
		}
	}
	return calc(left);
}

int main() {
	cout.precision(20);
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
