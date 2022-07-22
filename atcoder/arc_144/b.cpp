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

int64_t solve(int64_t N, int64_t a, int64_t b, std::vector<int64_t> A) {
	int64_t left = *min_element(A.begin(), A.end()), right = 1LL << 60;
	auto possible = [&](int64_t t) -> bool {
		int64_t ac = 0, bc = 0;
		for (int i = 0; i < N; ++i) {
			if (A[i] < t) {
				ac += (t - A[i] + a - 1) / a;
			} else {
				bc += (A[i] - t) / b;
			}
		}
		return ac <= bc;
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
	int64_t N, a, b;
	std::cin >> N >> a >> b;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, a, b, A) << endl;
	return 0;
}
