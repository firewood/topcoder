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
typedef long double LD;
typedef pair<LL, LL> II;
typedef pair<LD, II> DII;

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

void solve(long long N, std::vector<long long> &x, std::vector<long long> &y) {
	vector<DII> v;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; ++j) {
			LD dx = x[j] - x[i], dy = y[j] - y[i];
			v.emplace_back(DII(sqrt(dx * dx + dy * dy), II(i, j)));
		}
		LD dy = 100 - y[i];
		v.emplace_back(DII(sqrt(dy * dy), II(i, N)));
		dy = -100 - y[i];
		v.emplace_back(DII(sqrt(dy * dy), II(i, N + 1)));
	}
	sort(v.begin(), v.end());
	UnionFind uf(N + 2);
	LD ans = 0;
	for (auto kv : v) {
		uf.unite(kv.second.first, kv.second.second);
		if (uf.root(N) == uf.root(N + 1)) {
			ans = kv.first / 2;
			break;
		}
	}
	cout << ans << endl;
}

int main() {
    long long N;
	std::cin >> N;
	std::vector<long long> x(N), y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> x[i] >> y[i];
	}
	solve(N, x, y);
	return 0;
}
