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
typedef pair<int, II> III;

static const int INF = 1 << 30;
static const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] < _size[rb]) swap(ra, rb);
		_parent[rb] = ra, _size[ra] += _size[rb];
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

int solve(int N, vector<int> P) {
	int ans = 0;
	UnionFind uf(N * N);
	vector<vector<int>> total_costs(N, vector<int>(N, INF));
	vector<vector<int>> extra_costs(N, vector<int>(N, 1));
	auto bfs = [&](deque<III> &q) {
		while (!q.empty()) {
			int cost = q.front().first, y = q.front().second.first, x = q.front().second.second;
			q.pop_front();
			if (cost > total_costs[y][x]) {
				continue;
			}
			for (int dir = 0; dir < 4; ++dir) {
				int ny = y + dy[dir], nx = x + dx[dir];
				if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
					int next_cost = cost + extra_costs[ny][nx];
					if (next_cost < total_costs[ny][nx]) {
						total_costs[ny][nx] = next_cost;
						if (next_cost <= cost) {
							q.push_front(III(next_cost, II(ny, nx)));
						} else {
							q.push_back(III(next_cost, II(ny, nx)));
						}
					}
				}
			}
		}
	};
	deque<III> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == 0 || i == N - 1 || j == 0 || j == N - 1) {
				total_costs[i][j] = 0;
				q.push_front(III(0, II(i, j)));
			}
		}
	}
	bfs(q);
	for (int i = 0; i < N * N; ++i) {
		int y = P[i] / N, x = P[i] % N;
		ans += total_costs[y][x];
		total_costs[y][x] -= extra_costs[y][x];
		extra_costs[y][x] = 0;
		q.push_front(III(total_costs[y][x], II(y, x)));
		bfs(q);
	}
	return ans;
}

int main() {
	int N;
	cin >> N;
	std::vector<int> P(N * N);
	for (int i = 0; i < N * N; i++) {
		std::cin >> P[i];
		--P[i];
	}
	cout << solve(N, P) << endl;
	return 0;
}
