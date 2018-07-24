/*

Facebook Hacker Cup 2018 Round 1
B. Ethan Traverses a Tree


Constraints

1 <= T <= 80
1 <= K <= N <= 2.000
0 <= Ai, Bi <= N

*/

#include <cstdint>
#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

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

struct Solver {
	int n;
	int k;
	int left[2000];
	int right[2000];
	bool visited[2000];
	vector<int> vpre, vpost;

	void input() {
		cin >> n >> k;
		for (int i = 0; i < n; ++i) {
			int a, b;
			cin >> a >> b;
			left[i] = a - 1;
			right[i] = b - 1;
		}
	}

	vector<int> solve() {
		vector<int> r;
		pre(0);
		post(0);
		UnionFind uf(n);
		for (int i = 0; i < n; ++i) {
			uf.unite(vpre[i], vpost[i]);
		}
		bool ok = false;
		int col[2000];
		int c = 1;
		for (int i = 0; i < n; ++i) {
			if (uf.root(i) == i) {
				col[i] = c;
				if (c >= k) {
					ok = true;
				}
				if (++c > k) {
					c = 1;
				}
			}
		}
		if (ok) {
			for (int i = 0; i < n; ++i) {
				r.push_back(col[uf.root(i)]);
			}
		}
		return r;
	}

	void pre(int node) {
		if (node < 0) {
			return;
		}
		vpre.push_back(node);
		pre(left[node]);
		pre(right[node]);
	}

	void post(int node) {
		if (node < 0) {
			return;
		}
		post(left[node]);
		post(right[node]);
		vpost.push_back(node);
	}
};

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		Solver solver;
		solver.input();
		vector<int> ans = solver.solve();
		cout << "Case #" << t << ":";
		if (ans.empty()) {
			cout << " Impossible" << endl;
		} else {
			for (int a : ans) {
				cout << " " << a;
			}
			cout << endl;
		}
	}
	return 0;
}
