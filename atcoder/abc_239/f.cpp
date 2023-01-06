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

typedef pair<int, int> II;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] < _size[rb]) swap(ra, rb);
		_parent[rb] = ra, _size[ra] += _size[rb];
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

vector<II> solve(int N, int M, std::vector<int> D, std::vector<int> A, std::vector<int> B) {
	vector<II> ans;
	UnionFind uf(N);
	for (int i = 0; i < M; ++i) {
		uf.unite(A[i], B[i]);
		D[A[i]] -= 1;
		D[B[i]] -= 1;
	}
	map<int, vector<int>> m;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < D[i]; ++j) {
			m[uf.root(i)].emplace_back(i);
		}
	}
	set<int> ss, ds;
	for (auto kv : m) {
		if (kv.second.size() == 1) {
			ss.insert(kv.first);
		} else {
			ds.insert(kv.first);
		}
	}
	while (!ss.empty() && !ds.empty()) {
		int a = *ss.begin(), b = *ds.begin();
		ans.emplace_back(m[a].back(), m[b].back());
		uf.unite(a, b);
		ss.erase(a);
		m[b].pop_back();
		if (m[b].size() == 1) {
			ds.erase(b);
			ss.insert(b);
		}
	}
	if (ss.size() == 2) {
		int a = *ss.begin(), b = *ss.rbegin();
		ans.emplace_back(m[a].back(), m[b].back());
		uf.unite(a, b);
		ss.clear();
	}
	return uf.size(0) == N && ss.empty() && ds.empty() ? ans : vector<II>();
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> D(N);
	for (int i = 0; i < N; i++) {
		std::cin >> D[i];
	}
	std::vector<int> A(M), B(M);
	for (int i = 0; i < M; i++) {
		std::cin >> A[i] >> B[i];
		--A[i]; --B[i];
	}
	vector<II> ans = solve(N, M, D, A, B);
	if (!ans.empty()) {
		for (auto kv : ans) {
			cout << (kv.first + 1) << " " << (kv.second + 1) << endl;
		}
	} else {
		cout << -1 << endl;
	}
	return 0;
}
