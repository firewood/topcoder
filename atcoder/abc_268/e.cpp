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

int64_t solve(int64_t N, std::vector<int64_t> p) {
	vector<int> pos(N);
	for (int i = 0; i < N; ++i) {
		pos[p[i]] = i;
	}
	auto cost = [&](int64_t x) {
		x %= N;
		int64_t sum = 0;
		for (int i = 0; i < N; ++i) {
			sum += min((pos[i] + x - i + N * 2) % N, (i - (pos[i] + x) + N * 2) % N);
		}
		return sum;
	};
	int64_t ans = INF;
	int64_t left = 0, right = 2 * N;
	for (int64_t t = 0; t < 100; ++t) {
		int64_t lc = cost((left * 2 + right) / 3), rc = cost((left + right * 2) / 3);
		if (lc < rc) {
			ans = min(ans, lc);
			right = (left + right * 2) / 3;
		} else {
			ans = min(ans, rc);
			left = (left * 2 + right) / 3;
		}
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> p(N);
	for (int i = 0; i < N; i++) {
		std::cin >> p[i];
	}
	cout << solve(N, p) << endl;
	return 0;
}
