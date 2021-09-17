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

int64_t solve(int64_t W, int64_t H, std::vector<int64_t> p, std::vector<int64_t> q) {
	int64_t ans = 0;
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	int64_t wi = 0, hi = 0;
	while (wi < W || hi < H) {
		if (wi < W && (hi < H && p[wi] <= q[hi] || hi >= H)) {
			ans += p[wi++] * (H + 1 - hi);
		} else {
			ans += q[hi++] * (W + 1 - wi);
		}
	}
	return ans;
}

int main() {
	int64_t W, H;
	std::cin >> W >> H;
	std::vector<int64_t> p(W);
	for (int i = 0; i < W; i++) {
		std::cin >> p[i];
	}
	std::vector<int64_t> q(H);
	for (int i = 0; i < H; i++) {
		std::cin >> q[i];
	}
	cout << solve(W, H, p, q) << endl;
	return 0;
}
