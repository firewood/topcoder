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

typedef pair< int64_t, int64_t> II;

struct Tree {
	int64_t _size;
	vector<vector<int64_t>> _edges;
	vector<II> _ans;
	int _cnt;

	Tree(int64_t size) : _size(size), _edges(size), _ans(size) { }

	void build_edges(const vector<int64_t>& a, const vector<int64_t>& b) {
		for (int64_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	II dfs(int parent, int node) {
		int c = 0;
		II w(1LL<<30, -1);
		for (auto next_node : _edges[node]) {
			if (next_node == parent) continue;
			++c;
			II x = dfs(node, next_node);
			w.first = min(w.first, x.first);
			w.second = max(w.second, x.second);
		}
		if (!c) {
			++_cnt;
			w.first = _cnt;
			w.second = _cnt;
		}
		_ans[node] = w;
		return w;
	}
};

vector<II> solve(int64_t N, std::vector<int64_t> u, std::vector<int64_t> v) {
	Tree tree(N);
	tree.build_edges(u, v);
	tree._cnt = 0;
	tree.dfs(-1, 0);
	return tree._ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> u(N-1), v(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> u[i] >> v[i];
		--u[i];
		--v[i];
	}
	vector<II> ans = solve(N, u, v);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << (ans[i].first) << " " << (ans[i].second) << endl;
	}
	return 0;
}
