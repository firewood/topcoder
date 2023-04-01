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

int64_t solve(int64_t N, int64_t M) {
	int64_t ans = INF, sq = min(N, int64_t(sqrt(M) + 1));
	if (sq * sq >= M) {
		for (int64_t i = 1; i <= sq; ++i) {
			int64_t j = (M + i - 1) / i;
			if (j <= N) {
				ans = min(ans, i * j);
			}
		}
	}
	return ans < INF ? ans : -1;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	cout << solve(N, M) << endl;
	return 0;
}
