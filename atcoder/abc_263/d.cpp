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

int64_t solve(int64_t N, int64_t L, int64_t R, std::vector<int64_t> A) {
	vector<int64_t> rsum(N + 1);
	for (int i = N - 1; i >= 0; --i) {
		rsum[i] = min(rsum[i + 1] + A[i], R * (N - i));
	}
	int64_t ans = rsum[0], left_sum = 0;
	for (int i = 0; i < N; i++) {
		left_sum += A[i];
		ans = min(ans, min(left_sum, L * (i + 1)) + rsum[i + 1]);
	}
	return ans;
}

int main() {
	int64_t N, L, R;
	std::cin >> N >> L >> R;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, L, R, A) << endl;
	return 0;
}
