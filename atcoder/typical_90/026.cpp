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

struct Tree {
    int _size;
    int _root;
    vector<vector<int>> _edges;
    vector<int> _color;

    Tree(int size) : _root(0), _size(size), _edges(size), _color(size) { }

    void build_edges(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < a.size(); ++i) {
            _edges[a[i]].emplace_back(b[i]);
            _edges[b[i]].emplace_back(a[i]);
        }
    }

    void dfs(int n, int color) {
        _color[n] = color;
        for (auto next : _edges[n]) {
            if (_color[next] == 0) {
                dfs(next, -color);
            }
        }
    }
};

vector<int> solve(int N, std::vector<int> A, std::vector<int> B) {
    Tree tree(N);
    tree.build_edges(A, B);
    tree.dfs(0, 1);
    vector<int> x, y;
    for (int i = 0; i < N; i++) {
        (tree._color[i] > 0 ? x : y).emplace_back(i + 1);
    }
    return x.size() >= y.size() ? x : y;
}

int main() {
#if DEBUG || _DEBUG
//	freopen("in.txt", "r", stdin);
	freopen("in_1.txt", "r", stdin);
#endif
    int N;
	std::cin >> N;
	std::vector<int> A(N-1), B(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> A[i] >> B[i];
        --A[i]; --B[i];
	}
    vector<int> ans = solve(N, A, B);
    for (int i = 0; i < N / 2; ++i) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
	return 0;
}
