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

int64_t solve(int N, std::vector<int64_t> u, std::vector<int64_t> v, std::vector<int64_t> w) {
	int64_t ans = 0;
	UnionFind uf(N);
	vector<int> seq(w.size());
	iota(seq.begin(), seq.end(), 0);
	sort(seq.begin(), seq.end(), [&](int lhs, int rhs) {
		return w[lhs] < w[rhs];
	});
	for (auto i : seq) {
		int64_t a = u[i], b = v[i];
		ans += w[i] * uf.size(a) * uf.size(b);
		uf.unite(a, b);
	}
	return ans;
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int64_t> u(N - 1), v(N - 1), w(N - 1);
	for (int i = 0; i < N - 1; i++) {
		std::cin >> u[i] >> v[i] >> w[i];
		--u[i]; --v[i];
	}
	cout << solve(N, u, v, w) << endl;
	return 0;
}
