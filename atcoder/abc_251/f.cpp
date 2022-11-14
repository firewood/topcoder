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
	vector<vector<pair<int, int>>> _edges;
	vector<int> _vis;

	Tree(int64_t size) : _size(size), _edges(size), _vis(size) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int64_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(make_pair(b[i], i));
			_edges[b[i]].emplace_back(make_pair(a[i], i));
		}
	}

	void dfs(int n, vector<int> &ans) {
		_vis[n] += 1;
		for (auto next : _edges[n]) {
			if (_vis[next.first] <= 0) {
				ans.emplace_back(next.second);
				dfs(next.first, ans);
			}
		}
	}

	void bfs(int n, vector<int>& ans) {
		vector<int> q, vis(_size);
		q.emplace_back(n);
		vis[n] = 1;
		while (!q.empty()) {
			vector<int> nq;
			for (auto n : q) {
				for (auto next : _edges[n]) {
					if (vis[next.first] <= 0) {
						vis[next.first] = 1;
						ans.emplace_back(next.second);
						nq.emplace_back(next.first);
					}
				}
			}
			q = nq;
		}
	}
};

vector<int> solve(int N, int M, std::vector<int> u, std::vector<int> v) {
	vector<int> ans;
	Tree tree(N);
	tree.build_edges(u, v);
	tree.dfs(0, ans);
	tree.bfs(0, ans);
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> u(M), v(M);
	for (int i = 0; i < M; i++) {
		std::cin >> u[i] >> v[i];
		--u[i]; --v[i];
	}
	vector<int> ans = solve(N, M, u, v);
	for (auto x : ans) {
		cout << u[x] + 1 << " " << v[x] + 1 << endl;
	}
	return 0;
}
