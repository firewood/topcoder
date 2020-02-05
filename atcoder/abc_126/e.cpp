// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

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

int main(int argc, char* argv[]) {

#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, m, x, y, z, ans = 0;
		cin >> n >> m;
		if (n < 0) return 0;
		UnionFind uf(n);
		for (int i = 0; i < m; ++i) {
			cin >> x >> y >> z;
			uf.unite(x - 1, y - 1);
		}
		ans = n;
		for (int i = 0; i < n; ++i) {
			if (uf.root(i) == i) {
				ans -= uf.size(i) - 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
