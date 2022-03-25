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

int64_t calc(int64_t st, int64_t ed, int64_t t) {
	return (st + ed) * t / 2;
}

int64_t solve(int64_t N, int64_t M, vector<int64_t> X, vector<int64_t> Y) {
	int64_t v = 0, x = 0, ans = X[0];
	for (int i = 0; i < N; ++i) {
		int64_t vfirst = v + X[i], vlast = v + X[i] * Y[i];
		if (vfirst > 0 && vlast < 0) {
			int64_t t = -v / X[i];
			ans = max(ans, x + calc(vfirst, v + X[i] * t, t));
		}
		x += calc(vfirst, vlast, Y[i]);
		ans = max(ans, x);
		v = vlast;
	}
	return ans;
}

int main() {
	int64_t T, N, M;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cin >> N >> M;
		std::vector<int64_t> X(N), Y(N);
		for (int i = 0; i < N; i++) {
			std::cin >> X[i] >> Y[i];
		}
		cout << solve(N, M, X, Y) << endl;
	}
	return 0;
}
