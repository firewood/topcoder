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

void solve(int N, int M, std::vector<int> &a, std::vector<int> &b, std::vector<int> &y, int Q, std::vector<int> &v, std::vector<int> &w) {
	vector<int> ans(Q);
	UnionFind uf(N);
	vector<pair<int, int>> x(M), q(Q);
	for (int i = 0; i < M; ++i) {
		x[i].first = y[i];
		x[i].second = i;
	}
	sort(x.rbegin(), x.rend());
	for (int i = 0; i < Q; ++i) {
		q[i].first = w[i];
		q[i].second = i;
	}
	sort(q.rbegin(), q.rend());
	int xi = 0, qi = 0;
	for (int year = max(x.front().first, q.front().first); year >= 0; --year) {
		while (qi < Q && q[qi].first == year) {
			int i = q[qi].second;
			ans[i] = uf.size(v[i]);
			++qi;
		}
		while (xi < M && x[xi].first == year) {
			int i = x[xi].second;
			uf.unite(a[i], b[i]);
			++xi;
		}
	}
	for (int i = 0; i < Q; ++i) {
		cout << ans[i] << endl;
	}
}

int main() {
	int N, M, Q;
	cin >> N >> M;
	std::vector<int> a(M);
	std::vector<int> b(M);
	std::vector<int> y(M);
	for (int i = 0; i < M; i++) {
		cin >> a[i] >> b[i] >> y[i];
		a[i]--, b[i]--;
	}
	cin >> Q;
	std::vector<int> v(Q);
	std::vector<int> w(Q);
	for (int i = 0; i < Q; i++) {
		cin >> v[i] >> w[i];
		v[i]--;
	}
	solve(N, M, a, b, y, Q, v, w);
	return 0;
}
