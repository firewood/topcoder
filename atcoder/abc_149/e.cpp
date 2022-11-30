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

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A) {
	int64_t ans = 0;

	sort(A.rbegin(), A.rend());
	vector<int64_t> sum(N + 1);
	for (int i = 0; i < N; ++i) {
		sum[i + 1] = sum[i] + A[i];
	}

	auto count_if_eq_or_gt_x = [&](int64_t x) {
		int64_t cnt = 0, right = N - 1;
		for (int i = 0; i < N; ++i) {
			while (right >= 0 && A[i] + A[right] < x) {
				--right;
			}
			if (right < i) break;
			cnt += 2 * (right - i) + 1;
		}
		return cnt;
	};

	int64_t left = A.back() + A.back(), right = A.front() + A.front();
	while (right - left > 1) {
		int64_t mid = (right + left) / 2;
		if (count_if_eq_or_gt_x(mid) < M) {
			right = mid;
		} else {
			left = mid;
		}
	}

	int64_t cnt = 0;
	right = N - 1;
	for (int i = 0; i < N; ++i) {
		while (right >= 0 && A[i] + A[right] < left) {
			--right;
		}
		if (right < i) break;
		cnt += 2 * (right - i) + 1;
		ans += (sum[right + 1] - sum[i + 1] + (right - i + 1) * A[i]) * 2;
	}
	ans -= (cnt - M) * left;
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, M, A) << endl;
	return 0;
}
