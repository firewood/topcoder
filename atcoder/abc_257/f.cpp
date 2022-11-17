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

static const int64_t INF = 1LL << 60;

struct Tree {
	int64_t _size;
	vector<vector<int64_t>> _edges;
	vector<int64_t> _vis;

	Tree(int64_t size) : _size(size + 2), _edges(size + 2), _vis(size + 2) { }

	void build_edges(const vector<int64_t>& a, const vector<int64_t>& b) {
		for (size_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
			_edges[b[i]].emplace_back(a[i]);
		}
	}

	vector<int64_t> bfs(int64_t start_node) {
		vector<int64_t> dists(_size, INF), q;
		dists[start_node] = 0;
		q.emplace_back(start_node);
		for (int turn = 1; !q.empty(); ++turn) {
			vector<int64_t> nq;
			for (auto node : q) {
				for (auto next_node : _edges[node]) {
					if (dists[next_node] >= INF) {
						dists[next_node] = turn;
						nq.emplace_back(next_node);
					}
				}
			}
			q = nq;
		}
		return dists;
	}
};

vector<int64_t> solve(int64_t N, int64_t M, std::vector<int64_t> U, std::vector<int64_t> V) {
	vector<int64_t> ans;
	Tree tree(N);
	tree.build_edges(U, V);
	vector<int64_t> fwd = tree.bfs(1), rev = tree.bfs(N);
	for (int i = 1; i <= N; ++i) {
		int64_t dist = min({ fwd[N], fwd[0] + rev[i], fwd[i] + rev[0] });
		ans.emplace_back(dist < INF ? dist : -1);
	}
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> U(M), V(M);
	for (int i = 0; i < M; i++) {
		std::cin >> U[i] >> V[i];
	}
	vector<int64_t> ans = solve(N, M, U, V);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
