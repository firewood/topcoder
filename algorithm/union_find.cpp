#include <cstdio>
#include <cstring>
#include <cassert>
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


struct UnionFindWithUndo {
	std::vector<int> _parent;
	std::vector<pair<int, int>> _history;
	UnionFindWithUndo(int size) : _parent(size, -1) { }
	bool unite(int a, int b) {
		int ra = root(a), rb = root(b);
		_history.emplace_back(ra, _parent[ra]);
		_history.emplace_back(rb, _parent[rb]);
		if (ra == rb) return false;
		if (_parent[ra] > _parent[rb]) swap(ra, rb);
		_parent[ra] += _parent[rb];
		_parent[rb] = ra;
		return true;
	}
	int root(int a) {
		int parent = _parent[a];
		return parent < 0 ? a : root(parent);
	}
	int size(int a) {
		return -_parent[root(a)];
	}
	void undo() {
		if (_history.empty()) return;
		_parent[_history.back().first] = _history.back().second; _history.pop_back();
		_parent[_history.back().first] = _history.back().second; _history.pop_back();
	}
};



bool test() {
	UnionFind uf(16);
	uf.unite(1, 2);
	uf.unite(2, 3);
	uf.unite(3, 4);
	assert(uf.root(1) == uf.root(4));
	return true;
}

bool test_rollback() {
	for (int t = 0; t < 1000; ++t) {
		int N = 2 + (rand() % 18);
		UnionFind uf(N);
		UnionFindWithUndo ufu(N);
		for (int u = 0; u < 20; ++u) {
			int p, q;
			auto gen = [&]() {
				p = -1, q = -1;
				while (p == q) {
					p = rand() % N, q = rand() % N;
				}
			};
			gen();
			uf.unite(p, q);
			ufu.unite(p, q);
			gen();
			ufu.unite(p, q);
			ufu.undo();
			for (int i = 0; i < N; ++i) {
				assert(uf.root(i) == ufu.root(i));
				assert(uf.size(i) == ufu.size(i));
			}
		}
	}

	return true;
}

int main(int argc, char *argv[])
{
	if (test()) cout << "OK" << endl;
	if (test_rollback()) cout << "OK" << endl;
	return 0;
}
