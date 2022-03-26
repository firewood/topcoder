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
	vector<vector<int>> _edges;
	vector<int> _vis;
	vector<int> _loop;

	Tree(int64_t size) : _size(size), _edges(size), _vis(size), _loop(size) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int64_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
		}
	}

	void dfs(int64_t n, set<int>& s) {
		++_vis[n];
		s.insert(n);
		for (auto next : _edges[n]) {
			if (!_vis[next]) {
				dfs(next, s);
			}
			if (_loop[next]) {
				_loop[n] = 1;
			} else if (s.find(next) != s.end()) {
				for (auto x : s) {
					_loop[x] = 1;
				}
			}
		}
		s.erase(n);
	}
};

int64_t solve(int N, int M, std::vector<int> U, std::vector<int> V) {
	Tree tree(N);
	tree.build_edges(U, V);
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (!tree._vis[i]) {
			set<int> s;
			tree.dfs(i, s);
		}
	}
	return accumulate(tree._loop.begin(), tree._loop.end(), 0);
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> U(M), V(M);
	for (int i = 0; i < M; i++) {
		std::cin >> U[i] >> V[i];
		--U[i], --V[i];
	}
	cout << solve(N, M, U, V) << endl;
	return 0;
}
