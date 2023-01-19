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

LD solve(int64_t N, int64_t M, std::vector<std::string> c) {
	LD ans = 0;
	int sy, sx, gy, gx;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (c[i][j] == 's') sy = i, sx = j;
			if (c[i][j] == 'g') gy = i, gx = j;
		}
	}
	auto possible = [&](LD mx) {
		vector<vector<int>> vis(N, vector<int>(M));
		vector<pair<int, int>> q;
		LD cost_factor = 1.0;
		auto enqueue = [&](int y, int x, auto& nq) {
			const int dy[4] = { 0, 1, 0, -1 };
			const int dx[4] = { 1, 0, -1, 0 };
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir], nx = x + dx[dir];
				if (ny >= 0 && ny < N && nx >= 0 && nx < M &&
					c[ny][nx] != '#' && !vis[ny][nx] &&
					(c[ny][nx] - '0') * cost_factor >= mx) {
					vis[ny][nx] = 1;
					nq.emplace_back(ny, nx);
				}
			}
		};
		q.emplace_back(sy, sx);
		vis[sy][sx] = 1;
		for (int t = 1; !q.empty(); ++t) {
			cost_factor *= 0.99;
			vector<pair<int, int>> nq;
			for (auto [y, x] : q) {
				if (y == gy && x == gx) {
					return true;
				}
				enqueue(y, x, nq);
			}
			q = nq;
		}
		return false;
	};

	if (!possible(-0.1)) {
		return -1;
	}

	LD left = 0, right = 9;
	while (right - left > 1e-9) {
		LD mid = (left + right) / 2;
		if (!possible(mid)) {
			right = mid;
		} else {
			left = mid;
		}
	}
	return left;
}

int main() {
	cout.precision(20);
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<std::string> c(N);
	for (int i = 0; i < N; i++) {
		std::cin >> c[i];
	}
	cout << solve(N, M, c) << endl;
	return 0;
}
