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

void solve(int N, int M, std::vector<int> &A, std::vector<int> &B) {
	UnionFind uf(N);
	vector<vector<int>> edges(N);
	for (int i = 0; i < M; i++) {
		edges[A[i] - 1].emplace_back(B[i] - 1);
		edges[B[i] - 1].emplace_back(A[i] - 1);
	}
	int left = A[0] - 1, right = B[0] - 1;
	uf.unite(left, right);
	vector<int> path({left, right});
	while (true) {
		for (auto node : edges[left]) {
			if (uf.root(node) != uf.root(left)) {
				path.insert(path.begin(), node);
				uf.unite(node, left);
				left = node;
				goto next;
			}
		}
		for (auto node : edges[right]) {
			if (uf.root(node) != uf.root(right)) {
				path.emplace_back(node);
				uf.unite(node, right);
				right = node;
				goto next;
			}
		}
		break;
next:
		{}
	}
	cout << path.size() << endl;
	string sep = "";
	for (int node : path) {
		cout << sep << node + 1;
		sep = " ";
	}
	cout << endl;
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif

	int N, M;
	std::cin >> N >> M;
	std::vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
	}
	solve(N, M, A, B);
	return 0;
}
