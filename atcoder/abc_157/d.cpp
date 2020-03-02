// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <set>
#include <map>
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
		int n = -1, m = -1, k = -1, a, b, c, d;
		cin >> n >> m >> k;
		if (n < 0) return 0;
		UnionFind uf(n);
		set<int> g[100000], df[100000], blk[100000];
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			--a, --b;
			uf.unite(a, b);
			df[a].insert(b);
			df[b].insert(a);
		}
		for (int i = 0; i < k; ++i) {
			cin >> c >> d;
			--c, --d;
			blk[c].insert(d);
			blk[d].insert(c);
		}
		for (int i = 0; i < n; ++i) {
			int r = uf.root(i);
			g[r].insert(i);
		}
		for (int i = 0; i < n; ++i) {
			const set<int>& s = g[uf.root(i)];
			int cnt = s.size() - 1;
			for (int x : df[i]) {
				if (s.find(x) != s.end()) {
					--cnt;
				}
			}
			for (int x : blk[i]) {
				if (s.find(x) != s.end()) {
					--cnt;
				}
			}
			if (i) cout << " ";
			cout << cnt;
		}
		cout << endl;
	}
	return 0;
}
