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

const int INF = 1 << 29;

// 01-BFS
int solve(int H, int W, std::vector<std::string>& b) {
	vector<vector<int>> costs(H, vector<int>(W, INF));
	vector<vector<int>> dirty(H, vector<int>(W));
	costs[0][0] = 0;
	dirty[0][0] = 1;
	deque<II> q;
	q.push_front(II(0, 0));
	while (!q.empty()) {
		II top = q.front();
		q.pop_front();
		int y = top.first, x = top.second, cost = costs[y][x];
		if (!dirty[y][x]) {
			continue;
		}
		dirty[y][x] = 0;
		for (int dy = -2; dy <= 2; ++dy) {
			for (int dx = -2; dx <= 2; ++dx) {
				int dist = abs(dy) + abs(dx);
				if (dist == 0 || dist >= 4) continue;
				int ny = y + dy, nx = x + dx;
				if (ny >= 0 && ny < H && nx >= 0 && nx < W) {
					int extra_cost = !(dist == 1 && b[ny][nx] == '.');
					int next_cost = cost + extra_cost;
					if (next_cost < costs[ny][nx]) {
						costs[ny][nx] = next_cost;
						dirty[ny][nx] = 1;
						if (extra_cost) {
							q.push_back(II(ny, nx));
						} else {
							q.push_front(II(ny, nx));
						}
					}
				}
			}
		}
	}
	int cost = costs[H - 1][W - 1];
	return cost < INF ? cost : -1;
}

int main() {
	int H, W;
	std::cin >> H >> W;
	std::vector<std::string> a(H);
	for (int i = 0; i < H; i++) {
		std::cin >> a[i];
	}
	int ans = solve(H, W, a);
	cout << ans << endl;
	return 0;
}
