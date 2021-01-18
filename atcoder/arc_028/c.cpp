#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long LL;

#ifdef _MSC_VER
#include <intrin.h>
inline uint32_t calc_log_size(uint32_t size) { unsigned long i; _BitScanReverse(&i, size); return i + 1; }
#else
inline uint32_t calc_log_size(unsigned long size) { return 32 - __builtin_clz(size); }
#endif

struct Tree {
	int _size;
	int _log_size;
	int _root;
	vector<vector<int>> _edges;
	vector<int> _depths;
	vector<vector<int>> _dbltbl;
	vector<int> _offset;
	vector<int> _count;

	Tree(int size) : _root(0), _size(size), _edges(size) { }

	void build_edges_from_parents(const vector<int>& parents) {
		for (int i = 0; i < parents.size(); ++i) {
			if (parents[i] < 0) {
				_root = i;
			} else {
				_edges[parents[i]].emplace_back(i);
			}
		}
	}

	void build_edges_from_siblings(const vector<int>& siblings) {
		for (int i = 0; i < siblings.size(); ++i) {
			_edges[i + 1].emplace_back(siblings[i]);
			_edges[siblings[i]].emplace_back(i + 1);
		}
	}

	void build_order_table() {
		_offset = vector<int>(_size);
		_count = vector<int>(_size);
		int order = 0;
		get_children_size(-1, _root, order);
	}

	void build_depth() {
		_log_size = calc_log_size(_size);
		_dbltbl = vector<vector<int>>(_log_size, vector<int>(_size));
		_depths = vector<int>(_size);
		get_depth(-1, _root, 0);
	}

	void build_doubling_table() {
		if (_depths.empty()) build_depth();
		for (int k = 1; k < _log_size; ++k) {
			for (int i = 0; i < _size; ++i) {
				int j = _dbltbl[k - 1][i];
				_dbltbl[k][i] = j < 0 ? -1 : _dbltbl[k - 1][j];
			}
		}
	}

	void get_children_size(int parent, int node, int& order) {
		_offset[node] = order++;
		for (int next : _edges[node]) {
			if (next != parent) get_children_size(node, next, order);
		}
		_count[node] = order - _offset[node];
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
		assert(_log_size > 0 && !_dbltbl.empty());
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
};

void solve(int N, std::vector<int> &p) {
	LL ans = 0;
	Tree tree(N);
	tree.build_edges_from_siblings(p);
	tree.build_order_table();

	for (int i = 0; i < N; i++) {
		int size = 0;
		for (int child : tree._edges[i]) {
			if (tree._count[child] < tree._count[i]) {
				size = max(size, tree._count[child]);
			}
		}
		size = max(size, N - tree._count[i]);
		cout << size << endl;
	}
}

int main() {
	int N;
	std::cin >> N;
	std::vector<int> p(N - 1);
	for (int i = 0; i < N - 1; i++) {
		std::cin >> p[i];
	}
	solve(N, p);
	return 0;
}
