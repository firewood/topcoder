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
#include <random>

using namespace std;

typedef pair<int, int> II;

const int INF = 1 << 30;

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

struct Tree {
	int64_t _size;
	vector<set<II>> _edges;
	vector<int> _vis;
	vector<int> _p;

	Tree(int64_t size) : _size(size), _edges(size), _vis(size) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		UnionFind uf(_size);
		for (int i = 0; i < int(a.size()); ++i) {
			if (uf.root(a[i]) != uf.root(b[i])) {
				uf.unite(a[i], b[i]);
				_edges[a[i]].insert(II(b[i], i));
				_edges[b[i]].insert(II(a[i], i));
			}
		}
	}

	bool resolve(int node, int target, vector<int>& ans) {
		_vis[node] = 1;
		if (_p[node] == target) {
			return true;
		}
		for (auto kv : _edges[node]) {
			int next = kv.first;
			if (!_vis[next] && resolve(next, target, ans)) {
				ans.emplace_back(kv.second);
				swap(_p[node], _p[next]);
				return true;
			}
		}
		return false;
	}

	vector<int> resolve() {
		vector<int> ans;
		std::vector<int> seq(_size);
		iota(seq.begin(), seq.end(), 0);
		while (_p != seq) {
			for (int node = 0; node < _size; ++node) {
				if (_edges[node].empty() && _p[node] != node) {
					return {};
				}
				if (_edges[node].size() == 1) {
					_vis = vector<int>(_size);
					if (!resolve(node, node, ans)) {
						return {};
					}
					II first_path = *(_edges[node].begin());
					_edges[node].erase(first_path);
					_edges[first_path.first].erase(II(node, first_path.second));
				}
			}
		}
		return ans;
	}
};

vector<int> solve(int N, std::vector<int> P, int M, std::vector<int> a, std::vector<int> b) {
	Tree tree(N);
	tree._p = P;
	tree.build_edges(a, b);
	return tree.resolve();
}

int main() {
	int N, M;
	std::cin >> N;
	std::vector<int> P(N);
	for (int i = 0; i < N; i++) {
		std::cin >> P[i];
		--P[i];
	}
	std::cin >> M;
	std::vector<int> a(M), b(M);
	for (int i = 0; i < M; i++) {
		std::cin >> a[i] >> b[i];
		--a[i];
		--b[i];
	}
	std::vector<int> seq(N);
	iota(seq.begin(), seq.end(), 0);
	if (P == seq) {
		cout << "0" << endl;
	} else {
		vector<int> ans = solve(N, P, M, a, b);
		if (ans.empty()) {
			cout << "-1" << endl;
		} else {
			cout << ans.size() << endl;
			for (size_t i = 0; i < ans.size(); ++i) {
				if (i) cout << " ";
				cout << (ans[i] + 1);
			}
			cout << endl;
		}
	}

#ifdef _DEBUG
	{
		std::random_device seed_gen;
		std::mt19937 engine(seed_gen());
		for (int i = 0; i < 1000; ++i) {
			int N = 4 + (rand() % 4);
			std::vector<int> seq(N);
			iota(seq.begin(), seq.end(), 0);
			std::vector<int> goal = seq;
			shuffle(seq.begin(), seq.end(), engine);
			std::vector<int> prev = seq;
			set<II> s;
			for (int i = 0; i < N + 2; ++i) {
				int a = rand() % N;
				int b = rand() % N;
				if (a != b) {
					s.insert(II(min(a, b), max(a, b)));
				}
			}
			vector<int> a, b;
			for (auto kv : s) {
				a.emplace_back(kv.first);
				b.emplace_back(kv.second);
			}
			vector<int> ans = solve(N, seq, a.size(), a, b);
			if (!ans.empty()) {
				for (auto x : ans) {
					swap(seq[a[x]], seq[b[x]]);
				}
				if (seq != goal) {
					cerr << "FAILED!" << endl;
				}
			}
		}
	}
#endif

	return 0;
}
