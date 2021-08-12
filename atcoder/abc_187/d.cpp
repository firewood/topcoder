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

int64_t solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B) {
	int64_t asum = 0, bsum = 0;
	vector<pair<int64_t, int64_t>> q;
	for (int64_t i = 0; i < N; ++i) {
		q.emplace_back(make_pair(A[i] * 2 + B[i], i));
		asum += A[i];
	}
	sort(q.rbegin(), q.rend());
	int64_t ans;
	for (ans = 0; bsum <= asum && ans < N; ++ans) {
		bsum += A[q[ans].second] + B[q[ans].second];
		asum -= A[q[ans].second];
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	cout << solve(N, A, B) << endl;
	return 0;
}
