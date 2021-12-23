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

int64_t solve(int64_t N, std::vector<int64_t> x, std::vector<int64_t> y) {
	vector<II> v;
	for (int i = 0; i < N; ++i) {
		v.emplace_back(II(x[i], y[i]));
	}
	sort(v.begin(), v.end());
	int64_t left = 0, right = INF;
	auto possible = [&](int64_t t) -> bool {
		int64_t mn = INF, mx = 0;
		queue<II> q;
		for (int i = 0; i < N; ++i) {
			while (!q.empty() && (v[i].first - q.front().first) >= t) {
				mn = min(mn, q.front().second);
				mx = max(mx, q.front().second);
				q.pop();
			}
			if (mn + t <= v[i].second || v[i].second <= mx - t) {
				return true;
			}
			q.push(v[i]);
		}
		return false;
	};
	while (right - left > 1) {
		int64_t mid = (left + right) / 2;
		if (!possible(mid)) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return left;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> x(N), y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> y[i];
	}
	cout << solve(N, x, y) << endl;
	return 0;
}
