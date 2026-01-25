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

int64_t solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B) {
	vector<int> seq(N);
	iota(seq.begin(), seq.end(), 0);
	sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
		return A[lhs] == A[rhs]
			? B[lhs] > B[rhs]
			: A[lhs] < A[rhs];
	});
	vector<int64_t> table(N + 1, INF);
	// LIS
	for (int i = 0; i < N; ++i) {
		int64_t b = B[seq[i]];
		*lower_bound(table.begin(), table.end(), b) = b;
	}
	return lower_bound(table.begin(), table.end(), INF) - table.begin();
}

int main() {
	{
		int64_t N;
		std::cin >> N;
		std::vector<int64_t> A(N), B(N);
		for (int i = 0; i < N; i++) {
			std::cin >> A[i] >> B[i];
		}
		cout << solve(N, A, B) << endl;
	}
	return 0;
}
