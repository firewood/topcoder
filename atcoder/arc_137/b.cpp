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

int64_t solve(int64_t N, std::vector<int64_t> A) {
	int64_t ans = 1, d = 0, low = 0, high = 0, m = 0;
	for (int i = 0; i < N; ++i) {
		if (A[i] == 0) {
			if (++d >= high) {
				high = d;
				low = d;
			}
		} else {
			low = min(low, --d);
			m = max(m, high - low);
		}
	}
	ans += m;

	d = 0, low = 0, high = 0, m = 0;
	for (int i = 0; i < N; ++i) {
		if (A[i] == 0) {
			high = max(high, ++d);
			m = max(m, high - low);
		} else {
			if (--d <= low) {
				low = d;
				high = d;
			}
		}
	}
	ans += m;

	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, A) << endl;
	return 0;
}
