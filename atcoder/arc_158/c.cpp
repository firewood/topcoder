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
	int64_t ans = 0, b = 1;
	for (int i = 0; i < N; ++i) {
		for (auto c : to_string(A[i])) {
			ans += c - '0';
		}
	}
	ans *= 2 * N;
	vector<int64_t> r(N);
	for (int i = 0; i < 16; ++i) {
		b *= 10;
		for (int j = 0; j < N; ++j) {
			r[j] = A[j] % b;
		}
		sort(r.begin(), r.end());
		int right = N - 1;
		for (int j = 0; j < N; ++j) {
			while (right >= 0 && r[j] + r[right] >= b) {
				--right;
			}
			ans -= (N - right - 1) * 9;
		}
	}
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
