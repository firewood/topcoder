#include <algorithm>
#include <cassert>
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
};

void dfs(int node, int &count, vector<int> &offset, vector<int> &counts, vector<vector<int>> &edges) {
    offset[node] = count++;
    for (int next : edges[node]) {
        dfs(next, count, offset, counts, edges);
    }
    counts[node] = count - offset[node];
}

void solve1(int N, std::vector<int> &p, int Q, std::vector<int> &a, std::vector<int> &b) {
    vector<int> offset(N);
    vector<int> counts(N);
    vector<vector<int>> edges(N);
    int root = 0;
    for (int i = 0; i < N; ++i) {
        if (p[i] < 0) {
            root = i;
        } else {
            edges[p[i]].emplace_back(i);
        }
    }
    int count = 0;
    dfs(root, count, offset, counts, edges);
    for (int i = 0; i < Q; ++i) {
        bool ans = offset[a[i]] > offset[b[i]] && (offset[a[i]] < offset[b[i]] + counts[b[i]]);
        cout << (ans ? "Yes" : "No") << endl;
    }
}

void solve2(int N, std::vector<int> &p, int Q, std::vector<int> &a, std::vector<int> &b) {
    Tree tree(p);
    for (int i = 0; i < Q; ++i) {
        bool ans = tree.lca(a[i], b[i]) == b[i];
        cout << (ans ? "Yes" : "No") << endl;
    }
}

int main() {
#ifdef DEBUG
    freopen("in_2.txt", "r", stdin);
#endif

    int N, Q;
    std::cin >> N;
    std::vector<int> p(N);
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
        if (p[i] >= 0) --p[i];
    }
    std::cin >> Q;
    std::vector<int> a(Q), b(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> a[i] >> b[i];
        --a[i]; --b[i];
    }
    solve2(N, p, Q, a, b);
	return 0;
}
