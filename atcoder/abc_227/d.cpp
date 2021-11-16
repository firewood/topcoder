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

int64_t solve(int64_t N, int64_t K, std::vector<int64_t> A) {
	sort(A.rbegin(), A.rend());
	int64_t left = 0, right = 1LL << 60;
	auto possible = [&](int64_t t) -> bool {
		int64_t sum = 0;
		for (int i = 0; i < N; ++i) {
			sum += min(t, A[i]);
		}
		return sum >= K * t;
	};
	while (right - left > 1) {
		int64_t mid = (left + right) / 2;
		if (!possible(mid)) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return left;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, K, A) << endl;
	return 0;
}
