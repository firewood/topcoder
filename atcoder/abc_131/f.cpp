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

int64_t solve(int N, std::vector<int> x, std::vector<int> y) {
	int64_t ans = 0;
	const int MAX_SIZE = 100001;
	UnionFind uf(MAX_SIZE * 2);
	for (int i = 0; i < N; ++i) {
		uf.unite(x[i], y[i] + MAX_SIZE);
	}
	map<int, int64_t> mx, my;
	set<int> xs(x.begin(), x.end());
	for (auto v : xs) {
		mx[uf.root(v)] += 1;
	}
	set<int> ys(y.begin(), y.end());
	for (auto v : ys) {
		my[uf.root(v + MAX_SIZE)] += 1;
	}
	for (auto kv : mx) {
		ans += kv.second * my[kv.first];
	}
	return ans - N;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> x(N), y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> y[i];
	}
	cout << solve(N, x, y) << endl;
	return 0;
}
