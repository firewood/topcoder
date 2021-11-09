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

int64_t solve(int N, const vector<int64_t> &t, const vector<vector<int64_t>> &a) {
	int64_t ans = 0;
	UnionFind uf(N);
	for (int i = N - 1; i >= 0; --i) {
		if (uf.root(i) == uf.root(N - 1)) {
			ans += t[i];
			for (auto x : a[i]) {
				uf.unite(N - 1, x - 1);
			}
		}
	}
	return ans;
}

int main() {
	int64_t N, K;
	cin >> N;
	vector<int64_t> t(N);
	vector<vector<int64_t>> a(N);
	for (int i = 0; i < N; i++) {
		cin >> t[i] >> K;
		a[i].resize(K);
		for (int j = 0; j < K; ++j) {
			cin >> a[i][j];
		}
	}
	cout << solve(N, t, a) << endl;
	return 0;
}
