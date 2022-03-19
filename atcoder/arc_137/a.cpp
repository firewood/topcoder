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

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }

int64_t solve(int64_t L, int64_t R) {
	int64_t ans = 0;
	for (int64_t x = L; x < min(L + 100, R); ++x) {
		for (int64_t y = max(x + 1, R - 100); y <= R; ++y) {
			if (gcd(x, y) == 1) {
				ans = max(ans, y - x);
			}
		}
	}
	return ans;
}

int main() {
	int64_t L, R;
	std::cin >> L >> R;
	cout << solve(L, R) << endl;
	return 0;
}
