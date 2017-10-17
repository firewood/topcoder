// C.

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> II;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	std::vector<int> _edges;
	UnionFind(int size) : _parent(size, -1), _size(size, 1), _edges(size) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) {
			_parent[rb] = ra, _size[ra] += _size[rb], _edges[ra] += _edges[rb];
		} else {
			_parent[ra] = rb, _size[rb] += _size[ra], _edges[rb] += _edges[ra];
		}
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
	int &edges(int root) { return _edges[root]; }
};

int main(int argc, char *argv[])
{
	vector<II> e;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		e.push_back(II(a, b));
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		UnionFind uf(n + 1);
		for (int j = 0; j < m; ++j) {
			if (i != j) {
				uf.unite(e[j].first, e[j].second);
			}
		}
		ans += uf.size(1) != n;
	}
	cout << ans << endl;
	return 0;
}
