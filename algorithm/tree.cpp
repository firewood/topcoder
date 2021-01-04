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
inline uint32_t __builtin_clz(unsigned long value)
{
	unsigned long leading_zero = 0;
	_BitScanReverse(&leading_zero, value);
	return 31 - leading_zero;
}
#endif
inline uint32_t calc_log_size(unsigned long size) { return 32 - __builtin_clz(size); }

struct Tree {
	int _size;
	int _log_size;
	int _root;
	vector<vector<int>> _edges;
	vector<int> _depths;
	vector<vector<int>> _dbltbl;

	Tree(const vector<int>& parents) : _size((int)parents.size()) {
		build_edges_from_parents(parents);
		build_doubling_table();
	}

	void build_edges_from_parents(const vector<int> &parents) {
		_edges = vector<vector<int>>(_size);
		_depths = vector<int>(_size);
		for (int i = 0; i < _size; ++i) {
			if (parents[i] < 0) {
				_root = i;
			} else {
				_edges[parents[i]].emplace_back(i);
			}
		}
	}

	void get_depth(int parent, int node, int depth) {
		_dbltbl[0][node] = parent;
		_depths[node] = depth;
		for (int next : _edges[node]) {
			if (next != parent) get_depth(node, next, depth + 1);
		}
	}

	void build_doubling_table() {
		_log_size = calc_log_size(_size);
		_dbltbl = vector<vector<int>>(_log_size, vector<int>(_size));
		get_depth(-1, _root, 0);
		for (int k = 1; k < _log_size; ++k) {
			for (int i = 0; i < _size; ++i) {
				int j = _dbltbl[k - 1][i];
				_dbltbl[k][i] = j < 0 ? -1 : _dbltbl[k - 1][j];
			}
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

bool test() {
	const int N = 256;
	vector<int> parents(N);

	{
		for (int i = 0; i < N; ++i) {
			parents[i] = i == N - 1 ? -1 : i + 1;
		}
		Tree tree(parents);
		for (int i = 0; i < 1000; ++i) {
			int a = rand() % N, b = rand() % N;
			int c = tree.lca(a, b);
			assert(c == max(a, b));
		}
	}

	{
		iota(parents.begin(), parents.end(), -1);
		Tree tree(parents);
		for (int i = 0; i < 1000; ++i) {
			int a = rand() % N, b = rand() % N;
			int c = tree.lca(a, b);
			assert(c == min(a, b));
		}
	}

	return true;
}

int main(int argc, char* argv[]) {
	cout << (test() ? "OK" : "FAILED") << endl;
}
