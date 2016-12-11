// D.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>

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

int main(int argc, char *argv[]) {
	int N, K, L;
	cin >> N >> K >> L;
	UnionFind road(N), rail(N);
	for (int i = 0; i != K; ++i) {
		int p, q;
		cin >> p >> q;
		road.unite(p - 1, q - 1);
	}
	for (int i = 0; i != L; ++i) {
		int r, s;
		cin >> r >> s;
		rail.unite(r - 1, s - 1);
	}
	map<pair<int, int>, int> m;
	for (int i = 0; i != N; ++i) {
		pair<int, int> key = make_pair(road.root(i), rail.root(i));
		m[key] += 1;
	}
	for (int i = 0; i != N; ++i) {
		pair<int, int> key = make_pair(road.root(i), rail.root(i));
		cout << (i ? " " : "") << m[key];
	}
	cout << endl;
	return 0;
}
