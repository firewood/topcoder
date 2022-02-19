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

	Tree(int64_t size) : _size(size), _edges(size) { }

	void build_edges(const vector<int64_t>& a, const vector<int64_t>& b) {
		for (int64_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	void bfs(vector<int64_t> &order, vector<int64_t> &parents) {
		order = { 0 };
		parents = vector<int64_t>(_size, -1);
		vector<int64_t> q, vis(_size);
		q.emplace_back(0);
		vis[0] = 1;
		while (!q.empty()) {
			vector<int64_t> nq;
			for (auto node : q) {
				for (auto next_node : _edges[node]) {
					if (!vis[next_node]) {
						vis[next_node] = 1;
						parents[next_node] = node;
						nq.emplace_back(next_node);
						order.emplace_back(next_node);
					}
				}
			}
			q = nq;
		}
	}

	vector<int64_t> query(int64_t Q, vector<int64_t> X, vector<int64_t> V, vector<int64_t> K) {
		vector<int64_t> ans(Q), order, parents;
		bfs(order, parents);
		map<int, vector<int64_t>> m;
		for (int i = 0; i < Q; ++i) {
			m[V[i]].emplace_back(i);
		}
		vector<vector<int64_t>> top_values(_size);
		for (auto it = order.rbegin(); it != order.rend(); ++it) {
			int64_t node = *it, parent = parents[node];
			vector<int64_t>& v = top_values[node];
			v.emplace_back(X[node]);
			sort(v.rbegin(), v.rend());
			if (v.size() > 20) {
				v.resize(20);
			}
			for (auto x : m[node]) {
				ans[x] = v[K[x]];
			}
			if (parent >= 0) {
				for (auto x : v) {
					top_values[parent].emplace_back(x);
				}
			}
		}
		return ans;
	}
};

vector<int64_t> solve(int64_t N, int64_t Q, std::vector<int64_t> X, std::vector<int64_t> A, std::vector<int64_t> B, std::vector<int64_t> V, std::vector<int64_t> K) {
	Tree tree(N);
	tree.build_edges(A, B);
	return tree.query(Q, X, V, K);
}

int main() {
	int64_t N, Q;
	std::cin >> N >> Q;
	std::vector<int64_t> X(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i];
	}
	std::vector<int64_t> A(N-1), B(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> A[i] >> B[i];
		--A[i];
		--B[i];
	}
	std::vector<int64_t> V(Q), K(Q);
	for (int i = 0; i < Q; i++) {
		std::cin >> V[i] >> K[i];
		--V[i];
		--K[i];
	}
	vector<int64_t> ans = solve(N, Q, X, A, B, V, K);
	if (!ans.empty()) {
		for (size_t i = 0; i < ans.size(); ++i) {
			cout << ans[i] << endl;
		}
	}
	return 0;
}
