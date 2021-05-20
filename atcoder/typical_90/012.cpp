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

int H, W;

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

void fill(int y, int x, UnionFind &uf, vector<vector<int>> &used) {
    const int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
    for (int dir = 0; dir < 4; ++dir) {
        int ny = y + dy[dir], nx = x + dx[dir];
        if (ny >= 0 && ny < H && nx >= 0 && nx < W && used[ny][nx]) {
            if (uf.root(y * W + x) != uf.root(ny * W + nx)) {
                uf.unite(y * W + x, ny * W + nx);
                fill(ny, nx, uf, used);
            }
        }
    }
}

int main() {
#if DEBUG
	freopen("in_2.txt", "r", stdin);
#endif
    int Q, t, r, c, ra, ca, rb, cb;
    cin >> H >> W >> Q;
    UnionFind uf(H * W);
    vector<vector<int>> used(H, vector<int>(W));
    for (int i = 0; i < Q; ++i) {
        cin >> t;
        if (t == 1) {
            cin >> r >> c;
            --r, --c;
            used[r][c] = 1;
            fill(r, c, uf, used);
        } else {
            cin >> ra >> ca >> rb >> cb;
            --ra, --ca, --rb, --cb;
            cout << (used[ra][ca] && uf.root(ra * W + ca) == uf.root(rb * W + cb) ? "Yes" : "No") << endl;
        }
    }
	return 0;
}
