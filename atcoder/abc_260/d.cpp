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
#include <unordered_set>

using namespace std;

struct UnionFind {
    std::vector<int> _parent, _size;
    vector<unordered_set<int>> _value;
    UnionFind(int size) : _parent(size, -1), _size(size, 1), _value(size) { }
    void unite(int a, int b) {
        int ra = root(a), rb = root(b);
        if (ra == rb) { return; }
        if (_size[ra] < _size[rb]) swap(ra, rb);
        _parent[rb] = ra, _size[ra] += _size[rb];
        for (auto kv : _value[rb]) _value[ra].insert(kv);
    }
    int root(int a) {
        int p = _parent[a];
        if (p < 0) { return a; }
        while (_parent[p] >= 0) { p = _parent[p]; }
        return _parent[a] = p;
    }
    int size(int a) { return _size[root(a)]; }
};

vector<int> solve(int N, int K, std::vector<int> P) {
    UnionFind uf(N);
    vector<int> t(N, -1);
    set<int> s;
    for (int i = 0; i < N; ++i) {
        int x = P[i];
        if (K == 1) {
            t[x] = i + 1;
        } else {
            uf._value[x].insert(x);
            auto it = s.lower_bound(x);
            if (it == s.end()) {
                s.insert(x);
            } else {
                uf.unite(x, *it);
                s.erase(it);
                if (uf.size(uf.root(x)) < K) {
                    s.insert(x);
                } else {
                    for (auto z : uf._value[uf.root(x)]) {
                        t[z] = i + 1;
                    }
                }
            }
        }
    }
    return t;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    std::vector<int> P(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
        --P[i];
    }
    vector<int> ans = solve(N, K, P);
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
