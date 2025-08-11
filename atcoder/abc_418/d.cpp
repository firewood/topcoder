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

int64_t solve(int64_t N, std::string T) {
	int64_t ans = 0;
	vector<int64_t> dp(2);
	for (int i = 0; i < N; ++i) {
		int k = i % 2, rk = k ^ 1;
		vector<int64_t> next(2);
		int d = T[i] - '0';
		next[0] = dp[!d];
		next[1] = dp[d];
		next[d] += 1;
		ans += next[1];
		dp = next;
	}

	return ans;
}

int main() {
	int64_t N;
	std::string T;
	std::cin >> N >> T;
	cout << solve(N, T) << endl;
	return 0;
}
