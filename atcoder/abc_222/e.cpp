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

static const int64_t MOD = 998244353;

#ifdef _MSC_VER
#include <intrin.h>
inline uint32_t calc_log_size(uint32_t size) { unsigned long i; _BitScanReverse(&i, size); return i + 1; }
#else
inline uint32_t calc_log_size(unsigned long size) { return 32 - __builtin_clz(size); }
#endif

struct modint {
	int64_t x;
	modint() { }
	modint(int _x) : x(_x) { }
	operator int() const { return (int)x; }
	modint operator+(int y) { return (x + y + MOD) % MOD; }
	modint operator+=(int y) { x = (x + y + MOD) % MOD; return *this; }
	modint operator-(int y) { return (x - y + MOD) % MOD; }
	modint operator-=(int y) { x = (x - y + MOD) % MOD; return *this; }
	modint operator*(int y) { return (x * y) % MOD; }
	modint operator*=(int y) { x = (x * y) % MOD; return *this; }
	modint operator/(int y) { return (x * modpow(y, MOD - 2)) % MOD; }
	modint operator/=(int y) { x = (x * modpow(y, MOD - 2)) % MOD; return *this; }
	static modint modinv(int a) { return modpow(a, MOD - 2); }
	static modint modpow(int a, int b) {
		modint x = a, r = 1;
		for (; b; b >>= 1, x *= x) if (b & 1) r *= x;
		return r;
	}
};

struct Tree {
	int _size;
	int _log_size;
	int _root;
	vector<vector<pair<int, int>>> _edges;
	vector<int> _depths;
	vector<vector<int>> _dbltbl;
	vector<int> _offset;
	vector<int> _parent;
	vector<int> _parent_edge;
	vector<int> _count;

	Tree(int size) : _root(0), _size(size), _edges(size), _parent(size), _parent_edge(size) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(make_pair(b[i], i));
			_edges[b[i]].emplace_back(make_pair(a[i], i));
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
		get_depth(-1, -1, _root, 0);
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
		for (auto kv : _edges[node]) {
			int next = kv.first;
			if (next != parent) get_children_size(node, next, order);
		}
		_count[node] = order - _offset[node];
	}

	void get_depth(int parent, int parent_edge, int node, int depth) {
		_parent[node] = parent;
		_parent_edge[node] = parent_edge;
		_dbltbl[0][node] = parent;
		_depths[node] = depth;
		for (auto kv : _edges[node]) {
			int next = kv.first;
			if (next != parent) get_depth(node, kv.second, next, depth + 1);
		}
	}

	// 最小共通祖先: Lowest Common Ancestor
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
};

int64_t solve(int N, int M, int K, std::vector<int> A, std::vector<int> U, std::vector<int> V) {
	Tree tree(N);
	tree.build_edges(U, V);
	tree.build_doubling_table();
	vector<int> cnt(N, 0);
	for (int i = 1; i < M; ++i) {
		int a = A[i - 1], b = A[i];
		int p = tree.lca(a, b);
		while (a != p) {
			cnt[tree._parent_edge[a]] += 1;
			a = tree._parent[a];
		}
		while (b != p) {
			cnt[tree._parent_edge[b]] += 1;
			b = tree._parent[b];
		}
	}
	int tot = accumulate(cnt.begin(), cnt.end(), 0);
	int r = (tot + K) / 2, b = r - K;
	if (r < 0 || b < 0 || (r + b) != tot) {
		return 0;
	}
	vector<modint> dp(1000001, 0);
	dp[0] = 1;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = min(r, N * (i + 1)); j >= cnt[i]; --j) {
			dp[j] += dp[j - cnt[i]];
		}
	}
	return dp[r];
}

int main() {
	int N, M, K;
	std::cin >> N >> M >> K;
	std::vector<int> A(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i];
		--A[i];
	}
	std::vector<int> U(N-1), V(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> U[i] >> V[i];
		--U[i];
		--V[i];
	}
	cout << solve(N, M, K, A, U, V) << endl;
	return 0;
}
