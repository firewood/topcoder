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

int64_t solve(int64_t N, int64_t L, int64_t R) {
	int64_t ans = 0;
	for (int64_t b = 1; b <= R; b *= 2) {
		if (N & b) {
			int64_t low = max(L, b);
			int64_t high = min(R, b * 2 - 1);
			ans += max(int64_t(0), high - low + 1);
		}
	}
	return ans;
}

int main() {
	int64_t N, L, R;
	std::cin >> N >> L >> R;
	cout << solve(N, L, R) << endl;
	return 0;
}
