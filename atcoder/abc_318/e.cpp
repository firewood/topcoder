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
	int64_t ans = 0, tsum = 0;
	vector<int64_t> lcnt(N + 1), rcnt(N + 1), sum(N + 1);
	for (int i = 0; i < N; ++i) {
		rcnt[A[i]] += 1;
	}
	for (int i = 0; i < N; ++i) {
		ans += tsum - sum[A[i]];
		tsum -= sum[A[i]];
		sum[A[i]] = ++lcnt[A[i]] * --rcnt[A[i]];
		tsum += sum[A[i]];
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
