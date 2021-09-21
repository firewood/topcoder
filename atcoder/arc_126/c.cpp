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
	int64_t ans = 1, mx = *max_element(A.begin(), A.end());
	vector<int64_t> cnt(mx * 2 + 1), sum(mx * 2 + 1);
	for (int64_t i = 0; i < N; ++i) {
		cnt[A[i]] += 1;
		sum[A[i]] += A[i];
	}
	for (int64_t i = 1; i <= mx * 2; ++i) {
		cnt[i] += cnt[i - 1];
		sum[i] += sum[i - 1];
	}

	if (K >= (mx * N - sum[mx])) {
		return (sum[mx] + K) / N;
	}

	for (int64_t x = 2; x <= mx; ++x) {
		int64_t tot = 0, pc = 0, ps = 0;
		for (int k = 1; k * x < mx * 2; ++k) {
			tot += k * x * (cnt[k * x] - cnt[(k - 1) * x]) - (sum[k * x] - sum[(k - 1) * x]);
		}
		if (tot <= K) {
			ans = max(ans, x);
		}
	}
	return ans;
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
