
// B.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

typedef vector<int> IntVec;

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
	int N, M;
	{
		string s;
		getline(cin, s);
		stringstream ss(s);
		ss >> N >> M;
	}
	UnionFind uf(N);
	for (int i = 0; i < M; ++i) {
		string s;
		getline(cin, s);
		stringstream ss(s);
		int a, b;
		ss >> a >> b;
		uf.unite(a - 1, b - 1);
	}
	int ans = -1;
	for (int i = 0; i < N; ++i) {
		if (uf.root(i) == i) {
			++ans;
		}
	}
	cout << ans << endl;
}
