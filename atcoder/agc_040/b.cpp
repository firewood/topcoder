#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

const LL INF = 1LL << 60;

void solve(long long N, std::vector<long long>& L, std::vector<long long>& R) {
	vector<int> vi(N);
	iota(vi.begin(), vi.end(), 0);
	sort(vi.begin(), vi.end(), [&](int lhs, int rhs) {
		return make_pair(L[lhs], -R[lhs]) < make_pair(L[rhs], -R[rhs]);
	});

	LL ans = 0;
	LL common = max(0LL, *min_element(R.begin(), R.end()) - *max_element(L.begin(), L.end()) + 1);
	vector<LL> right(N + 1, INF);
	for (LL i = N - 1; i >= 0; --i) {
		right[i] = min(right[i + 1], R[vi[i]]);
		ans = max(ans, R[i] - L[i] + 1 + common);
	}

	LL rightmost = INF;
	for (LL i = 0; i < N - 1; ++i) {
		rightmost = min(rightmost, R[vi[i]]);
		ans = max(ans, max(0LL, rightmost - L[vi[i]] + 1) + max(0LL, right[i + 1] - L[vi[N - 1]] + 1));
	}

	cout << ans << endl;
}

int main() {
	long long N;
	std::cin >> N;
	std::vector<long long> L(N);
	std::vector<long long> R(N);
	for (int i = 0; i < N; i++) {
		std::cin >> L[i];
		std::cin >> R[i];
	}
	solve(N, L, R);
	return 0;
}
