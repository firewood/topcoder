#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

void solve(long long N, std::vector<int> &x, std::vector<int> &y) {
	vector<int> vi(N);
	iota(vi.begin(), vi.end(), 0);
	sort(vi.begin(), vi.end(), [&](int lhs, int rhs) {
		return make_pair(x[lhs], y[lhs]) < make_pair(x[rhs], y[rhs]);
	});
	UnionFind uf(N);
	map<int, int> m;
	for (int i = 0; i < N; ++i) {
		int yy = y[vi[i]];
		auto it = m.lower_bound(yy);
		if (it != m.begin()) {
			while (it != m.begin()) {
				--it;
				uf.unite(vi[i], it->second);
				if (it != m.begin()) {
					it = m.erase(it);
				}
			}
		} else {
			m[yy] = vi[i];
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << uf.size(uf.root(i)) << endl;
	}
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<int> x(N), y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> y[i];
	}
	solve(N, x, y);
	return 0;
}
