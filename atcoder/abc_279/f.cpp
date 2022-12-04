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

int main() {
	int64_t N, Q, type, x, y;
	cin >> N >> Q;
	UnionFind uf(600002);
	vector<int> b(600002, -1), pos(600002, -1);
	iota(b.begin(), b.begin() + N, 0);
	iota(pos.begin(), pos.begin() + N, 0);
	int nb = N;
	for (int tt = 0; tt < Q; ++tt) {
		cin >> type >> x;
		--x;
		if (type == 1) {
			cin >> y;
			--y;
			int& p = b[x], & q = b[y];
			if (p < 0 && q < 0) continue;
			if (p < 0) {
				p = q;
			} else if (q >= 0) {
				uf.unite(p, q);
			}
			q = -1;
			pos[uf.root(p)] = x;
		}
		if (type == 2) {
			int& p = b[x];
			int q = nb++;
			if (p < 0) {
				p = q;
			} else {
				uf.unite(p, q);
			}
			pos[uf.root(p)] = x;
		}
		if (type == 3) {
			cout << (pos[uf.root(x)] + 1) << endl;
		}
	}
	return 0;
}
