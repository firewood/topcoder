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

int64_t solve(int64_t N, int64_t L, int64_t W, std::vector<int64_t> a) {
	a.emplace_back(L);
	int64_t ans = 0, right = 0;
	for (int i = 0; i <= N; ++i) {
		int64_t left = a[i];
		int64_t c = max(int64_t(0), (left - right + W - 1) / W);
		ans += c;
		right = max(right + c * W, left + W);
	}
	return ans;
}

int main() {
	int64_t N, L, W;
	std::cin >> N >> L >> W;
	std::vector<int64_t> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	cout << solve(N, L, W, a) << endl;
	return 0;
}
