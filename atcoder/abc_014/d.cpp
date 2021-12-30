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

#ifdef _MSC_VER
#include <intrin.h>
inline uint32_t calc_log_size(uint32_t size) { unsigned long i; _BitScanReverse(&i, size); return i + 1; }
#else
inline uint32_t calc_log_size(unsigned long size) { return 32 - __builtin_clz(size); }
#endif

struct Tree {
	int _size;
	int _log_size;
	vector<vector<int>> _edges;
	vector<int> _depths;
	vector<vector<int>> _dbltbl;

	Tree(int size) : _size(size), _edges(size) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	void build_doubling_table(int root) {
		if (_depths.empty()) build_depth(root);
		for (int k = 1; k < _log_size; ++k) {
			for (int i = 0; i < _size; ++i) {
				int j = _dbltbl[k - 1][i];
				_dbltbl[k][i] = j < 0 ? -1 : _dbltbl[k - 1][j];
			}
		}
	}

	void build_depth(int root) {
		_log_size = calc_log_size(_size);
		_dbltbl = vector<vector<int>>(_log_size, vector<int>(_size));
		_depths = vector<int>(_size);
		get_depth(-1, 0, 0);
	}

	void get_depth(int parent, int node, int depth) {
		_dbltbl[0][node] = parent;
		_depths[node] = depth;
		for (int next : _edges[node]) {
			if (next != parent) get_depth(node, next, depth + 1);
		}
	}

	// Å¬‹¤’Ê‘cæ: Lowest Common Ancestor
	int lca(int a, int b) {
		if (_depths[a] > _depths[b]) swap(a, b);
		for (int k = _log_size - 1; k >= 0; --k) {
			if ((_depths[b] - _depths[a]) & (1 << k)) b = _dbltbl[k][b];
		}
		if (a == b) return a;
		for (int k = _log_size - 1; k >= 0; --k) {
			if (_dbltbl[k][a] != _dbltbl[k][b]) {
				a = _dbltbl[k][a], b = _dbltbl[k][b];
			}
		}
		return _dbltbl[0][a];
	}

	int get_distance_by_lca(int a, int b) {
		return _depths[a] + _depths[b] - _depths[lca(a, b)] * 2;
	}
};

vector<int> solve(int N, std::vector<int> x, std::vector<int> y, int64_t Q, std::vector<int> a, std::vector<int> b) {
	vector<int> ans(Q);
	Tree tree(N);
	tree.build_edges(x, y);
	tree.build_doubling_table(0);
	for (int i = 0; i < Q; ++i) {
		ans[i] = tree.get_distance_by_lca(a[i], b[i]) + 1;
	}
	return ans;
}

int main() {
	int N, Q;
	std::cin >> N;
	std::vector<int> x(N-1), y(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> x[i] >> y[i];
		--x[i];
		--y[i];
	}
	std::cin >> Q;
	std::vector<int> a(Q), b(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> a[i] >> b[i];
		--a[i];
		--b[i];
	}
	vector<int> ans = solve(N, x, y, Q, a, b);
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}
