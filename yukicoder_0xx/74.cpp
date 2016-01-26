#include <iostream>
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
	int N;
	cin >> N;
	int tot = 0;
	UnionFind uf(N);
	int D[256], W[256], OK[256] = {}, CNT[256] = {};
	for (int i = 0; i < N; ++i) {
		cin >> D[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> W[i];
		tot += W[i];
	}
	for (int i = 0; i < N; ++i) {
		int a = (i - (D[i] % N) + N) % N, b = (i + D[i]) % N;
		uf.unite(a, b);
	}
	for (int i = 0; i < N; ++i) {
		int a = (i - (D[i] % N) + N) % N, b = (i + D[i]) % N;
		if (a == b) {
			OK[uf.root(i)] = 1;
		}
		CNT[uf.root(i)] += W[i];
	}
	bool ans = true;
	for (int i = 0; i < N; ++i) {
		if (uf.root(i) == i) {
			int sz = uf.size(i);
			int cnt = CNT[i];
			if (!OK[i] && (uf.size(i) - CNT[i]) % 2) {
				ans = false;
				break;
			}
		}
	}
	if (tot >= N) {
		ans = true;
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
