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
	int64_t _size;
	vector<vector<int64_t>> _edges;
	vector<int64_t> _vis;
	vector<int64_t> _routes;

	Tree(int64_t size) : _size(size), _edges(size), _vis(size) { }

	void build_edges(const vector<int64_t>& a, const vector<int64_t>& b) {
		for (int64_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	void dfs(int64_t parent, int64_t n) {
		_routes.emplace_back(n);
		_vis[n] = 1;
		for (auto next : _edges[n]) {
			if (!_vis[next]) {
				dfs(n, next);
				_routes.emplace_back(n);
			}
		}
	}
};

vector<int64_t> solve(int64_t N, std::vector<int64_t> A, std::vector<int64_t> B) {
	vector<int64_t> ans;
	Tree tree(N);
	tree.build_edges(A, B);
	for (int i = 0; i < N; ++i) {
		sort(tree._edges[i].begin(), tree._edges[i].end());
	}
	tree.dfs(0, 0);
	return tree._routes;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int64_t> A(N-1), B(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> A[i] >> B[i];
		--A[i]; --B[i];
	}
	vector<int64_t> ans = solve(N, A, B);
	for (int i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << (ans[i] + 1);
	}
	cout << endl;
	return 0;
}
