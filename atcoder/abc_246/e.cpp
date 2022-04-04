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
static const int dx[4] = { -1,-1,1,1 };
static const int dy[4] = { -1,1,-1,1 };

int64_t solve(int64_t N, int64_t A_x, int64_t A_y, int64_t B_x, int64_t B_y, std::vector<std::string> S) {
	vector<vector<vector<int64_t>>> costs(N, vector<vector<int64_t>>(N, vector<int64_t>(4, INF)));
	deque<III> q;
	for (int i = 0; i < 4; ++i) {
		costs[A_x][A_y][i] = 1;
		q.push_front(III(i, II(A_x, A_y)));
	}
	while (!q.empty()) {
		III top = q.front();
		q.pop_front();
		int64_t prev_dir = top.first, x = top.second.first, y = top.second.second, cost = costs[x][y][prev_dir];
		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N && S[nx][ny] != '#') {
				int64_t nc = cost + (prev_dir != dir);
				if (costs[nx][ny][dir] <= nc) {
					continue;
				}
				costs[nx][ny][dir] = nc;
				if (prev_dir == dir) {
					q.push_front(III(dir, II(nx, ny)));
				} else {
					q.push_back(III(dir, II(nx, ny)));
				}
			}
		}
	}
	int64_t ans = *min_element(costs[B_x][B_y].begin(), costs[B_x][B_y].end());
	return ans < INF ? ans : -1;
}

int main() {
	int64_t N, A_x, A_y, B_x, B_y;
	std::cin >> N >> A_x >> A_y >> B_x >> B_y;
	--A_x, --A_y, --B_x, --B_y;
	std::vector<std::string> S(N);
	for (int i = 0; i < N; i++) {
		std::cin >> S[i];
	}
	cout << solve(N, A_x, A_y, B_x, B_y, S) << endl;
	return 0;
}
