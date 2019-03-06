// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; } else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<II> v(m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		v[i].first = a - 1;
		v[i].second = b - 1;
	}
	UnionFind uf(n);
	vector<LL> ans(m);
	LL d = ((LL)n * (n - 1)) / 2;
	for (int i = m - 1; i >= 0; --i) {
		ans[i] = d;
		if (uf.root(v[i].first) != uf.root(v[i].second)) {
			d -= (LL)uf.size(v[i].first) * uf.size(v[i].second);
			uf.unite(v[i].first, v[i].second);
		}
	}
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
