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
	int64_t ans = accumulate(A.begin(), A.end(), int64_t(0));
	vector<int64_t> cnt(30);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 30; ++j) {
			cnt[j] += (A[i] >> j) & 1;
		}
	}
	for (int i = 0; i < N; ++i) {
		int64_t sum = 0;
		for (int j = 0; j < 30; ++j) {
			sum += (1LL << j) * (((A[i] >> j) & 1) ? (N - cnt[j]) : cnt[j]);
		}
		ans = max(ans, sum);
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
