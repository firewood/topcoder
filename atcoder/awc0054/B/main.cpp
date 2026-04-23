#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int64_t, int64_t> II;

int64_t solve(int64_t N, int64_t W, std::vector<int64_t> l, std::vector<int64_t> w) {
	int64_t ans = 0, last = 0;
	vector<II> v;
	for (int64_t i = 0; i < N; ++i) {
		v.emplace_back(II(l[i], l[i] + w[i]));
	}
	sort(v.begin(), v.end());
	for (int64_t i = 0; i < N; ++i) {
		ans += max(int64_t(0), v[i].second - max(v[i].first, last));
		last = max(last, v[i].second);
	}
	return ans;
}

int main() {
	int64_t N, W;
	std::cin >> N >> W;
	std::vector<int64_t> l(N), w(N);
	for (int64_t i = 0; i < N; ++i) {
		std::cin >> l[i] >> w[i];
	}
	auto ans = solve(N, W, std::move(l), std::move(w));
	cout << ans << endl;
}
