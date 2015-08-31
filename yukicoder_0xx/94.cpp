#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

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

int main(int argc, char *argv[])
{
	cout.precision(16);
	int N;
	cin >> N;
	int X[1000], Y[1000];
	long double dist[1000][1000];
	UnionFind uf(1000);
	for (int i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
		for (int j = 0; j < i; ++j) {
			int dx = X[i] - X[j], dy = Y[i] - Y[j];
			dist[i][j] = sqrt(dx * dx + dy * dy);
			if (dist[i][j] <= 10) {
				uf.unite(i, j);
			}
		}
	}
	long double m = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (uf.root(i) == uf.root(j)) {
				m = max(m, dist[i][j]);
			}
		}
	}
	if (N == 0) {
		m = 1;
	} else {
		m += 2;
	}
	cout << m << endl;
	return 0;
}
