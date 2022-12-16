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
	vector<vector<int>> _edges;
	vector<int> _vis;

	Tree(int size) : _size(size), _edges(size) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	void get_distance(int parent_node, int node, int dist, int& max_dist_node, int& max_dist) {
		if (dist > max_dist) {
			max_dist_node = node;
			max_dist = dist;
		}
		for (auto next_node : _edges[node]) {
			if (next_node != parent_node) {
				get_distance(node, next_node, dist + 1, max_dist_node, max_dist);
			}
		}
	}

	// 直径を求める
	int get_diameter(int& start, int& end) {
		int max_dist = 0;
		get_distance(-1, 0, 0, start, max_dist);
		max_dist = 0;
		get_distance(-1, start, 0, end, max_dist);
		if (start > end) swap(start, end);
		return max_dist;
	}

	void dfs(int node, const vector<int>& K, const vector<vector<int>>& links, vector<int>& path, vector<int>& ans) {
		_vis[node] = 1;
		for (int qi : links[node]) {
			int k = K[qi];
			if (k <= path.size()) {
				ans[qi] = path[path.size() - k] + 1;
			}
		}
		path.emplace_back(node);
		for (int next_node : _edges[node]) {
			if (!_vis[next_node]) {
				dfs(next_node, K, links, path, ans);
			}
		}
		path.pop_back();
	}
};

vector<int> solve(int N, std::vector<int> A, std::vector<int> B, int Q, std::vector<int> U, std::vector<int> K) {
	vector<int> ans(Q, -1), path;
	Tree tree(N);
	tree.build_edges(A, B);
	int start, end;
	tree.get_diameter(start, end);
	vector<vector<int>> links(N);
	for (int i = 0; i < Q; ++i) {
		links[U[i]].emplace_back(i);
	}
	tree._vis = vector<int>(N);
	tree.dfs(start, K, links, path, ans);
	tree._vis = vector<int>(N);
	tree.dfs(end, K, links, path, ans);
	return ans;
}

int main() {
	int N, Q;
	std::cin >> N;
	std::vector<int> A(N-1), B(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> A[i] >> B[i];
		--A[i], --B[i];
	}
	std::cin >> Q;
	std::vector<int> U(Q), K(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> U[i] >> K[i];
		--U[i];
	}
	vector<int> ans = solve(N, A, B, Q, U, K);
	for (size_t i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
