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

int64_t solve(std::vector<int64_t> h, std::vector<int64_t> w) {
	int64_t ans = 0;
	for (int a = 1; a <= 28; ++a) {
		for (int b = 1; b <= 28; ++b) {
			int c = h[0] - a - b;
			if (c <= 0) continue;
			for (int d = 1; d <= 28; ++d) {
				for (int e = 1; e <= 28; ++e) {
					int f = h[1] - d - e;
					if (f <= 0) continue;
					int p = w[0] - a - d, q = w[1] - b - e, r = w[2] - c - f;
					ans += p > 0 && q > 0 && r > 0 && p + q + r == h[2];
				}
			}
		}
	}
	return ans;
}

int main() {
	std::vector<int64_t> h(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> h[i];
	}
	std::vector<int64_t> w(3);
	for (int i = 0; i < 3; i++) {
		std::cin >> w[i];
	}
	cout << solve(h, w) << endl;
	return 0;
}
