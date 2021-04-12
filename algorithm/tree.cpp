#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cassert>

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

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
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

	void get_distance(int parent_node, int node, int dist, int& max_dist_node, int& max_dist) {
		if (dist > max_dist) {
			max_dist_node = node;
			max_dist = dist;
		}
		for (auto next_node : _edges[node]) {
			if (next_node != parent_node) {
				get_distance(node, next_node, dist + 1, max_dist_node, max_dist);
			}
		}
	}

	// 最小共通祖先: Lowest Common Ancestor
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

	// 直径を求める
	int get_diameter(int &start, int &end) {
		int max_dist = 0;
		get_distance(-1, 0, 0, start, max_dist);
		get_distance(-1, start, 0, end, max_dist);
		if (start > end) swap(start, end);
		return max_dist;
	}
};

bool test1() {
	//	assert(calc_log_size(0) == 0);
	assert(calc_log_size(1) == 1);
	assert(calc_log_size(2) == 2);
	assert(calc_log_size(3) == 2);
	assert(calc_log_size(4) == 3);
	assert(calc_log_size(8) == 4);
	assert(calc_log_size(16) == 5);
	return true;
}

bool test2() {
	const int N = 256;
	vector<int> parents(N);

	{
		for (int i = 0; i < N; ++i) {
			parents[i] = i == N - 1 ? -1 : i + 1;
		}
		Tree tree(N);
		tree.build_edges_from_parents(parents);
		tree.build_doubling_table();
		for (int i = 0; i < 1000; ++i) {
			int a = rand() % N, b = rand() % N;
			int c = tree.lca(a, b);
			assert(c == max(a, b));
		}
	}

	{
		iota(parents.begin(), parents.end(), -1);
		Tree tree(N);
		tree.build_edges_from_parents(parents);
		tree.build_doubling_table();
		for (int i = 0; i < 1000; ++i) {
			int a = rand() % N, b = rand() % N;
			int c = tree.lca(a, b);
			assert(c == min(a, b));
		}
	}

	return true;
}

int main(int argc, char* argv[]) {
	cout << (test1() ? "OK" : "FAILED") << endl;
	cout << (test2() ? "OK" : "FAILED") << endl;
}
