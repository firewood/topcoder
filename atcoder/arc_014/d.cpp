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

typedef pair<int64_t, int64_t> II;

static const int64_t INF = 1LL << 60;

vector<int64_t> solve(int64_t all, int64_t N, int64_t M, std::vector<int64_t> L, std::vector<int64_t> x, std::vector<int64_t> y) {
	vector<int64_t> ans(M), diffs;
	vector<II> v;
	for (int i = 1; i < N; ++i) {
		diffs.emplace_back(L[i] - L[i - 1] - 1);
	}
	for (int i = 0; i < M; ++i) {
		v.emplace_back(x[i] + y[i], i);
	}
	sort(diffs.begin(), diffs.end());
	diffs.emplace_back(INF);
	sort(v.begin(), v.end());
	int64_t sum = N, cnt = N - 1, dist = 0, di = 0;
	for (auto kv : v) {
		int64_t xy = kv.first, xx = x[kv.second], yy = y[kv.second];
		while (xy > diffs[di]) {
			sum += (diffs[di] - dist) * cnt;
			--cnt;
			dist = diffs[di++];
		}
		sum += (xy - dist) * cnt;
		dist = xy;
		ans[kv.second] = sum + min(xx, L[0]) + min(yy, all - L.back() - 1);
	}
	return ans;
}

int main() {
	int64_t all, N, M;
	std::cin >> all >> N >> M;
	std::vector<int64_t> L(N);
	for (int i = 0; i < N; i++) {
		std::cin >> L[i];
		--L[i];
	}
	std::vector<int64_t> x(M), y(M);
	for (int i = 0; i < M; i++) {
		std::cin >> x[i] >> y[i];
	}
	vector<int64_t> ans = solve(all, N, M, L, x, y);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
