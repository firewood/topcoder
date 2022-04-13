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

int64_t solve(int64_t N, int64_t X, int64_t Y, std::vector<int64_t> A) {
	int64_t ans = 0, st = INF, xr = -1, yr = -1;
	for (int64_t i = 0; i < N; ++i) {
		if (A[i] < Y || A[i] > X) {
			st = INF, xr = -1, yr = -1;
		} else {
			st = min(st, i);
			if (A[i] == X) {
				xr = i;
			}
			if (A[i] == Y) {
				yr = i;
			}
			ans += max(min(xr, yr) - st + 1, int64_t(0));
		}
	}
	return ans;
}

int main() {
	int64_t N, X, Y;
	std::cin >> N >> X >> Y;
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	cout << solve(N, X, Y, A) << endl;
	return 0;
}
