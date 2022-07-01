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

int64_t solve(int64_t N, std::vector<int64_t> x, std::vector<int64_t> y, std::vector<int64_t> P) {
	int64_t ans = 1e12;
	for (int i = 0; i < N; ++i) {
		int64_t pow = 0;
		vector<int64_t> done(N);
		priority_queue<II, vector<II>, greater<>> q;
		q.emplace(II(1, i));
		while (!q.empty()) {
			int64_t cost = q.top().first, i = q.top().second;
			q.pop();
			if (done[i]) continue;
			pow = max(pow, cost);
			done[i] = 1;
			for (int j = 0; j < N; ++j) {
				if (!done[j]) {
					int64_t d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
					q.emplace(II((d + P[i] - 1) / P[i], j));
				}
			}
		}
		ans = min(ans, pow);
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> x(N), y(N), P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> y[i] >> P[i];
	}
	cout << solve(N, x, y, P) << endl;
	return 0;
}
