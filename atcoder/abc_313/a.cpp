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

int64_t solve(int64_t N, std::vector<int64_t> P) {
	int64_t ans = 0;
	for (int i = 1; i < N; ++i) {
		if (P[i] >= P[0]) {
			ans = max(ans, P[i] + 1 - P[0]);
		}
	}
	return ans;
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
	}
	cout << solve(N, P) << endl;
	return 0;
}
