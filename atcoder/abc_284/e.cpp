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

struct Tree {
	int64_t _size;
	vector<vector<int64_t>> _edges;
	vector<int64_t> _vis;

	Tree(int64_t size) : _size(size + 2), _edges(size + 2), _vis(size + 2) { }

	void build_edges(const vector<int64_t>& a, const vector<int64_t>& b) {
		for (size_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	void dfs(int64_t n, int64_t &cnt) {
		if (cnt >= 1000000) return;
		_vis[n] += 1;
		++cnt;
		for (auto next : _edges[n]) {
			if (_vis[next] <= 0) {
				dfs(next, cnt);
			}
		}
		_vis[n] -= 1;
	}
};

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> u, std::vector<int64_t> v) {
	int64_t ans = 0;
	Tree tree(N);
	tree.build_edges(u, v);
	int64_t cnt = 0;
	tree.dfs(0, cnt);
	return cnt;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> u(M), v(M);
	for (int i = 0; i < M; i++) {
		std::cin >> u[i] >> v[i];
		--u[i]; --v[i];
	}
	cout << solve(N, M, u, v) << endl;
	return 0;
}
