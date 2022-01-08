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

typedef pair<int, int> II;

set<II> solve(int N, int K, std::vector<int> x, std::vector<int> y) {
	set<II> ans;
	map<II, vector<int>> m;
	int64_t k2 = int64_t(K) * K;
	for (int i = 0; i < N; ++i) {
		II key(x[i] / K, y[i] / K);
		m[key].emplace_back(i);
	}
	for (auto kv : m) {
		for (int dx = -1; dx <= 1; ++dx) {
			int nx = kv.first.first + dx;
			for (int dy = -1; dy <= 1; ++dy) {
				int ny = kv.first.second + dy;
				II key(nx, ny);
				if (m.find(key) != m.end()) {
					for (auto a : kv.second) {
						int x1 = x[a], y1 = y[a];
						for (auto b : m[key]) {
							if (a == b) continue;
							int x2 = x[b], y2 = y[b];
							int64_t dx = x2 - x1, dy = y2 - y1;
							if (dx * dx + dy * dy <= k2) {
								ans.insert(II(min(a, b), max(a, b)));
							}
						}
					}
				}
			}
		}
	}
	return ans;
}

int main() {
	int N, K;
	std::cin >> N >> K;
	std::vector<int> x(N), y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> y[i];
	}
	set<II> ans = solve(N, K, x, y);
	cout << ans.size() << endl;
	if (!ans.empty()) {
		for (auto kv : ans) {
			cout << (kv.first + 1) << " " << (kv.second + 1) << endl;
		}
	}
	return 0;
}
