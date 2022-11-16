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

	// 01-BFS
	bool bfs01(int64_t start_node, int64_t N, int64_t K, vector<int64_t> A, vector<int64_t> B) {
		vector<int64_t> seqs(_size, INF);
		deque<int64_t> q;
		seqs[start_node] = B[0] == A[start_node - 1];
		q.push_front(start_node);
		while (!q.empty()) {
			int64_t top = q.front();
			q.pop_front();
			int64_t node = top, seq = seqs[node];
			for (auto next_node : _edges[node]) {
				if (seq < K && B[seq] == A[next_node - 1]) {
					if (seq + 1 < seqs[next_node]) {
						seqs[next_node] = seq + 1;
						q.push_back(next_node);
					}
				} else {
					if (seq < seqs[next_node]) {
						seqs[next_node] = seq;
						q.push_front(next_node);
					}
				}
			}
		}
		return seqs[N] == B.size();
	}

};

bool solve(int64_t N, int64_t M, int64_t K, std::vector<int64_t> U, std::vector<int64_t> V, std::vector<int64_t> A, std::vector<int64_t> B) {
	Tree tree(N);
	tree.build_edges(U, V);
	return tree.bfs01(1, N, K, A, B);
}

int main() {
	int64_t N, M, K;
	std::cin >> N >> M >> K;
	std::vector<int64_t> U(M), V(M);
	for (int i = 0; i < M; i++) {
		std::cin >> U[i] >> V[i];
	}
	std::vector<int64_t> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}
	std::vector<int64_t> B(K);
	for (int i = 0; i < K; i++) {
		std::cin >> B[i];
	}
	cout << (solve(N, M, K, U, V, A, B) ? "Yes" : "No") << endl;
	return 0;
}
