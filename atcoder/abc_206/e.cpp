#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

int64_t solve(int64_t L, int64_t R) {
	vector<int64_t> cnt(R + 1);
	for (int64_t g = R; g >= 2; --g) {
		cnt[g] = (R / g - (L - 1) / g) * (R / g - (L - 1) / g);
		for (int64_t x = g * 2; x <= R; x += g) {
			cnt[g] -= cnt[x];
		}
	}
	int64_t ans = accumulate(cnt.begin(), cnt.end(), 0LL);
	for (int g = max(int64_t(2), L); g <= R; ++g) {
		ans -= 2 * (R / g - (L - 1) / g) - 1;
	}
	return ans;
}

int main() {
	int64_t L, R;
	std::cin >> L >> R;
	cout << solve(L, R) << endl;
	return 0;
}
