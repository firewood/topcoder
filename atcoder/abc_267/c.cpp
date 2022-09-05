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

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A) {
	int64_t ans = -INF, a = 0, b = 0;
	for (int64_t i = 0; i < M - 1; ++i) {
		a += A[i];
		b += (i + 1) * A[i];
	}
	for (int i = M - 1; i < N; ++i) {
		b += M * A[i];
		ans = max(ans, b);
		a += A[i];
		b -= a;
		a -= A[i - M + 1];
	}
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
