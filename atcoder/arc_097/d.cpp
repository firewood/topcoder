// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

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
	int n, m;
	cin >> n >> m;
	vector<int> p(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
	}
	UnionFind uf(n + 1);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		uf.unite(x, y);
	}
	set<int> r[100001];
	for (int i = 1; i <= n; ++i) {
		r[uf.root(i)].insert(p[i]);
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		const set<int> &s = r[uf.root(i)];
		if (p[i] == i || s.find(i) != s.end()) {
			++ans;
		}
	}
	cout << ans << endl;
	return 0;
}
