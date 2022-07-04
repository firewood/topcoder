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

static const int64_t INF = 1LL << 60;

int64_t solve(int64_t N, int64_t X, std::vector<int64_t> A, std::vector<int64_t> B) {
	int64_t ans = INF, mn = INF, cost = 0;
	for (int i = 0; i < N; ++i) {
		cost += A[i] + B[i];
		X = max(int64_t(0), X - 1);
		mn = min(mn, B[i]);
		ans = min(ans, cost + X * mn);
	}
	return ans;
}

int main() {
	int64_t N, X;
	std::cin >> N >> X;
	std::vector<int64_t> A(N), B(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i] >> B[i];
	}
	cout << solve(N, X, A, B) << endl;
	return 0;
}
