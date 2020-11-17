#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

struct UnionFind {
	std::vector<int> _parent, _size;
	vector<unordered_map<int, int>> _value;
	UnionFind(int size) : _parent(size, -1), _size(size, 1), _value(size) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b);
		if (ra == rb) { return; }
		if (_size[ra] < _size[rb]) swap(ra, rb);
		_parent[rb] = ra, _size[ra] += _size[rb];
		for (auto kv : _value[rb]) _value[ra][kv.first] += kv.second;
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

int main() {
	int n, q, t, a, b, c;
	cin >> n >> q;
	UnionFind uf(n);
	for (int i = 0; i < n; ++i) {
		cin >> c;
		uf._value[i][c - 1] += 1;
	}
	for (int i = 0; i < q; ++i) {
		cin >> t >> a >> b;
		--a, --b;
		if (t == 1) {
			uf.unite(a, b);
		} else {
			cout << uf._value[uf.root(a)][b] << endl;
		}
	}
	return 0;
}
