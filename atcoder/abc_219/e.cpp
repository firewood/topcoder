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

int64_t solve(std::vector<std::vector<int64_t>> A) {
	int house_flags = 0, house_position = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (A[i][j]) {
				house_flags |= 1 << (i * 4 + j);
				house_position = ((i + 1) * 6 + j + 1);
			}
		}
	}
	int64_t ans = 0;
	for (int b = 1; b < (1 << 16); ++b) {
		if ((b & house_flags) != house_flags) continue;
		int f[6][6] = {};
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				f[i + 1][j + 1] = (b & (1 << (i * 4 + j))) != 0;
			}
		}
		UnionFind uf(36);
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				const int dy[4] = { -1,1,0,0 }, dx[4] = { 0,0,-1,1 };
				for (int dir = 0; dir < 4; ++dir) {
					int y = i + dy[dir], x = j + dx[dir];
					if (y >= 0 && y < 6 && x >= 0 && x < 6 && f[i][j] == f[y][x]) {
						uf.unite(i * 6 + j, y * 6 + x);
					}
				}
			}
		}
		ans += uf.size(uf.root(0)) + uf.size(uf.root(house_position)) == 36;
	}
	return ans;
}

int main() {
	std::vector<std::vector<int64_t>> A(4, std::vector<int64_t>(4));
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cin >> A[i][j];
		}
	}
	cout << solve(A) << endl;
	return 0;
}
