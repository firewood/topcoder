// C.

#include <iostream>
#include <sstream>
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

int main(int argc, char *argv[]) {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	for (int i = 0; i < h; ++i) {
		cin >> s[i];
	}
	UnionFind uf(h * w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (i > 0) {
				if (s[i - 1][j] != s[i][j]) {
					uf.unite((i - 1) * w + j, i * w + j);
				}
			}
			if (j > 0) {
				if (s[i][j - 1] != s[i][j]) {
					uf.unite(i * w + j - 1, i * w + j);
				}
			}
		}
	}
	vector<LL> a(h * w), b(h * w);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			int r = uf.root(i * w + j);
			if (s[i][j] == '#') {
				a[r]++;
			} else {
				b[r]++;
			}
		}
	}
	LL ans = 0;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			int k = i * w + j;
			if (uf.root(k) == k) {
				ans += a[k] * b[k];
			}
		}
	}
	cout << ans << endl;
	return 0;
}
