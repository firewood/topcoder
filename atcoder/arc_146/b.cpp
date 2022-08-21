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

int64_t solve(int64_t N, int64_t M, int64_t K, std::vector<int64_t> A) {
	int64_t ans = 0;
	auto possible = [&](int64_t target) {
		vector<int64_t> r(N);
		for (int i = 0; i < N; ++i) {
			int64_t current = A[i];
			for (int64_t b = 1LL << 30; b > 0; b >>= 1) {
				if ((target & b) != 0 && (current & b) == 0) {
					int64_t next = (current | (b - 1)) + 1;
					r[i] += next - current;
					current = next;
				}
			}
		}
		sort(r.begin(), r.end());
		return accumulate(r.begin(), r.begin() + K, int64_t(0)) <= M;
	};
	for (int64_t b = 1LL << 30; b > 0; b >>= 1) {
		if (possible(ans | b)) {
			ans |= b;
		}
	}
	return ans;
}

int main() {
	int64_t N, M, K;
	std::cin >> N >> M >> K;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, M, K, A) << endl;
	return 0;
}
