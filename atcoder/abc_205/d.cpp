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

void solve(int64_t N, int64_t Q, std::vector<int64_t> A, std::vector<int64_t> K) {
	int64_t ans = 0;
	for (int i = 0; i < Q; i++) {
		int64_t left = K[i], right = K[i] + 1e6;
		auto calc = [&](int64_t x) -> int64_t {
			return x - (lower_bound(A.begin(), A.end(), x) - A.begin());
		};
		while (right - left > 1) {
			int64_t mid = (left + right) / 2;
			int64_t x = calc(mid);
			if (x > K[i]) {
				right = mid;
			} else {
				left = mid;
			}
		}
		cout << left << endl;
	}
}

int main() {
	int64_t N, Q;
	std::cin >> N >> Q;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> K(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> K[i];
	}
	solve(N, Q, std::move(A), std::move(K));
	return 0;
}
