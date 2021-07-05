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

int64_t solve(int64_t P) {
	vector<int> dp(10000001, 1 << 29);
	dp[0] = 0;
	int64_t x = 1;
	for (int i = 1; i <= 10; ++i) {
		x *= i;
		for (int j = x; j <= 10000000; ++j) {
			dp[j] = min(dp[j], dp[j - x] + 1);
		}
	}
	return dp[P];
}

int main() {
	int64_t P;
	std::cin >> P;
	cout << solve(P) << endl;
	return 0;
}
