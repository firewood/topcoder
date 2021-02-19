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

int solve(int H, int W, std::vector<std::string>& S) {
	UnionFind uf(H + W);
	S[0][0] = S[0][W - 1] = S[H - 1][0] = S[H - 1][W - 1] = '#';
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (S[i][j] == '#') {
				uf.unite(i, H + j);
			}
		}
	}
	set<int> row, col;
	for (int i = 0; i < H; ++i) {
		row.insert(uf.root(i));
	}
	for (int j = 0; j < W; ++j) {
		col.insert(uf.root(H + j));
	}
	return min(row.size(), col.size()) - 1;
}

int main() {
    int H, W;
	std::cin >> H >> W;
	std::vector<std::string> S(H);
	for (int i = 0; i < H; i++) {
		std::cin >> S[i];
	}
	cout << solve(H, W, S) << endl;
	return 0;
}
