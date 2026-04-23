#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

struct Tree {
	int64_t _size;
	vector<vector<int64_t>> _edges;
	vector<int64_t> _vis;

	Tree(int64_t size) : _size(size + 2), _edges(size + 2), _vis(size + 2) { }

	void build_edges(const vector<int64_t>& a, const vector<int64_t>& b) {
		for (size_t i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i]);
		}
	}

	void dfs(int64_t n) {
		_vis[n] += 1;
		for (auto next : _edges[n]) {
			if (_vis[next] <= 0) {
				dfs(next);
			}
		}
	}
};

int64_t solve(int64_t N, int64_t M, std::vector<int64_t> A, std::vector<int64_t> B) {
	Tree tree(N);
	tree.build_edges(A, B);
	tree.dfs(0);
	int64_t ans = accumulate(tree._vis.begin(), tree._vis.end(), 0);
	return ans;
}

int main() {
	int64_t N, M;
	std::cin >> N >> M;
	std::vector<int64_t> A(M), B(M);
	for (int64_t i = 0; i < M; ++i) {
		std::cin >> A[i] >> B[i];
		--A[i];
		--B[i];
	}
	auto ans = solve(N, M, std::move(A), std::move(B));
	cout << ans << endl;
}
