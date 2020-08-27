// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
typedef long long LL;


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

int main(int argc, char *argv[])
{
	int n, m, k, l;
	cin >> n >> m;
	UnionFind uf(m);
	vector<int> lang(n, -1);
	for (int i = 0; i < n; ++i) {
		cin >> k;
		for (int j = 0; j < k; ++j) {
			cin >> l;
			--l;
			if (lang[i] < 0) {
				lang[i] = l;
			} else {
				uf.unite(lang[i], l);
			}
		}
	}
	int r = uf.root(lang[0]);
	bool ans = true;
	for (int i = 1; i < n; ++i) {
		if (uf.root(lang[i]) != r) {
			ans = false;
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
