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

typedef long double LD;
typedef pair<int64_t, int64_t> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

int64_t solve(int64_t N, std::vector<int64_t> L, std::vector<int64_t> R) {
	int64_t ans = INF, left = *min_element(L.begin(), L.end()), right = *max_element(R.begin(), R.end());
	auto cost = [&](int64_t m) {
		vector<int64_t> a(N), sum(N + 1);
		for (int i = 0; i < N; ++i) {
			a[i] = m <= L[i] ? L[i] : (min(m, R[i]));
		}
		sort(a.begin(), a.end());
		int64_t tot = 0, a0 = a[0];
		for (int i = 0; i < N; ++i) {
			a[i] -= a0;
			sum[i + 1] = sum[i] + a[i];
		}
		for (int i = 0; i < N; ++i) {
			tot += a[i] * i - sum[i];
			tot += sum[N] - sum[i] - (a[i] * (N - i));
		}
		return tot;
	};
	for (int64_t t = 0; t < 50; ++t) {
		int64_t lc = cost((left * 2 + right) / 3);
		int64_t rc = cost((left + right * 2) / 3);
		ans = min({ ans, lc, rc });
		if (lc < rc) {
			right = (left + right * 2) / 3;
		} else {
			left = (left * 2 + right) / 3;
		}
	}
	return ans / 2;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> L(N), R(N);
	for (int i = 0; i < N; i++) {
		std::cin >> L[i] >> R[i];
	}
	cout << solve(N, L, R) << endl;
	return 0;
}
