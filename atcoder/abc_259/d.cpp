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

bool solve(int64_t N, int64_t s_x, int64_t s_y, int64_t t_x, int64_t t_y, std::vector<int64_t> x, std::vector<int64_t> y, std::vector<int64_t> r) {
	x.emplace_back(s_x);
	x.emplace_back(t_x);
	y.emplace_back(s_y);
	y.emplace_back(t_y);
	r.emplace_back(0);
	r.emplace_back(0);
	int64_t sz = x.size();
	UnionFind uf(sz);
	for (int i = 0; i < sz; ++i) {
		for (int j = i + 1; j < sz; ++j) {
			int64_t dx = x[i] - x[j], dy = y[i] - y[j], d = dx * dx + dy * dy, rr = r[i] + r[j], rd = r[i] - r[j];
			if (d >= rd * rd && d <= rr * rr) {
				uf.unite(i, j);
			}
		}
	}
	return uf.root(N) == uf.root(N + 1);
}

int main() {
	int64_t N, s_x, s_y, t_x, t_y;
	std::cin >> N >> s_x >> s_y >> t_x >> t_y;
	std::vector<int64_t> x(N), y(N), r(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> y[i] >> r[i];
	}
	cout << (solve(N, s_x, s_y, t_x, t_y, x, y, r) ? "Yes" : "No") << endl;
	return 0;
}
