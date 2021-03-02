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

typedef long long LL;

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

LL solve(int N, int M, std::vector<int> &a, std::vector<int> &x, std::vector<int> &y) {
	LL ans = 0;
	UnionFind uf(N);
	for (int i = 0; i < M; i++) {
		uf.unite(x[i], y[i]);
	}
	if (uf.size(0) == N) {
		return 0;
	}
	int rc = 2 * (N - M - 1);
	if (N < rc) {
		return -1;
	}
	vector<vector<int>> v(N);
	for (int i = 0; i < N; i++) {
		v[uf.root(i)].emplace_back(a[i]);
	}
	vector<int> rv;
	for (int i = 0; i < N; i++) {
		if (uf.root(i) == i) {
			--rc;
			sort(v[i].begin(), v[i].end());
			ans += v[i].front();
			for (size_t j = 1; j < v[i].size(); ++j) {
				rv.emplace_back(v[i][j]);
			}
		}
	}
	sort(rv.begin(), rv.end());
	ans += accumulate(rv.begin(), rv.begin() + rc, 0LL);
	return ans;
}

int main() {
    int N, M;
	std::cin >> N >> M;
	std::vector<int> a(N);
	for (int i = 0; i < N; i++) {
		std::cin >> a[i];
	}
	std::vector<int> x(M), y(M);
	for (int i = 0; i < M; i++) {
		std::cin >> x[i] >> y[i];
	}
	LL ans = solve(N, M, a, x, y);
	if (ans < 0) {
		cout << "Impossible" << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}
