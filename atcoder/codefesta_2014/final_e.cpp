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

int64_t solve(int64_t N, std::vector<int64_t> R) {
	int64_t ans = 1, prev = R[0], dir = 0;
	for (int i = 1; i < N; ++i) {
		if (R[i] < prev) {
			ans += dir != -1;
			dir = -1;
			prev = min(prev, R[i]);
		} else if (R[i] > prev) {
			ans += dir != 1;
			dir = 1;
			prev = max(prev, R[i]);
		}
	}
	return ans < 3 ? 0 : ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> R(N);
	for (int i = 0; i < N; i++) {
		std::cin >> R[i];
	}
	cout << solve(N, R) << endl;
	return 0;
}
