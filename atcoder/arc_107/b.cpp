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

int64_t calc(int64_t n, int64_t a) {
	return a <= n + 1 ? (a - 1) : (2 * n - a + 1);
}

int64_t solve(int64_t N, int64_t K) {
	int64_t ans = 0;
	for (int64_t a = 2; a <= 2 * N; ++a) {
		int64_t b = a - K;
		if (b >= 2 && b <= 2 * N) {
			ans += calc(N, a) * calc(N, b);
		}
	}
	return ans;
}

int main() {
	int64_t N, K;
	std::cin >> N >> K;
	cout << solve(N, K) << endl;
	return 0;
}
