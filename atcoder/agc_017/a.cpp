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

int64_t solve(int64_t N, int64_t P, std::vector<int64_t> A) {
	int64_t ans = 0;
	vector<int64_t> dp = { 1, 0 };
	for (int i = 0; i < N; ++i) {
		dp = { dp[0] + dp[A[i] % 2], dp[1] + dp[!(A[i] % 2)] };
	}
	return dp[P];
}

int main() {
	int64_t N, P;
	std::cin >> N >> P;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, P, A) << endl;
	return 0;
}
