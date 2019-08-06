// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	std::vector<int> _values;
	UnionFind(int size) : _parent(size, -1), _size(size, 1), _values(size, -1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) {
			_parent[rb] = ra, _size[ra] += _size[rb];
			if (_values[rb] >= 0) {
				_values[ra] = _values[rb];
			}
		} else {
			_parent[ra] = rb, _size[rb] += _size[ra];
			if (_values[ra] >= 0) {
				_values[rb] = _values[ra];
			}
		}
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
	int& value(int node) { return _values[root(node)]; }
};

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int len = (int)s.length();
	vector<LL> vis(len, -1);
	UnionFind uf(len);
	for (int i = 0; i < len; ++i) {
		int x = i;
		while (vis[x] < 0) {
			vis[x] = 0;
			if (s[x] == 'L') {
				uf.unite(x, x - 1);
				--x;
			} else {
				uf.unite(x, x + 1);
				++x;
			}
			if (vis[x] >= 0) {
				if (uf.value(x) < 0) {
					uf.value(x) = x;
				}
			}
		}
	}
	vector<int> count(len);
	for (int i = 0; i < len; ++i) {
		int pos = uf.value(i);
		if (abs(pos - i) % 2) {
			if (s[pos] == 'L') {
				--pos;
			} else {
				++pos;
			}
		}
		count[pos] += 1;
	}
	for (int i = 0; i < len; ++i) {
		if (i) cout << " ";
		cout << count[i];
	}
	cout << endl;
	return 0;
}
