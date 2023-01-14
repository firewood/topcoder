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

#ifdef _MSC_VER
#define popcount __popcnt64
#else
#define popcount __builtin_popcountll
#endif

typedef pair<int, int> II;

struct Tree {
	int64_t _size;
	vector<vector<II>> _edges;

	Tree(int64_t size) : _size(size), _edges(size) { }

	void build_edges(const vector<int>& a, const vector<int>& b) {
		for (int i = 0; i < a.size(); ++i) {
			_edges[a[i]].emplace_back(b[i], i);
			_edges[b[i]].emplace_back(a[i], i);
		}
	}

	bool dfs(int n, int goal, int parent, int64_t &vis) {
		if (n == goal) return true;
		for (auto kv : _edges[n]) {
			int next = kv.first;
			if (next == parent) continue;
			if (dfs(next, goal, n, vis)) {
				vis |= 1LL << kv.second;
				return true;
			}
		}
		return false;
	}
};

int64_t solve(int N, std::vector<int> a, std::vector<int> b, int M, std::vector<int> u, std::vector<int> v) {
	int64_t ans = 0;
	Tree tree(N);
	tree.build_edges(a, b);
	vector<int64_t> vis(M);
	for (int i = 0; i < M; ++i) {
		tree.dfs(u[i], v[i], -1, vis[i]);
	}
	for (int i = 0; i < (1 << M); ++i) {
		int64_t mask = 0;
		for (int j = 0; j < M; ++j) {
			if (i & (1 << j)) mask |= vis[j];
		}
		int64_t white = popcount(mask), now = 1LL << (N - 1 - white);
		ans += (popcount(i) % 2) ? -now : now;
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N;
	std::vector<int> a(N-1), b(N-1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> a[i] >> b[i];
		--a[i]; --b[i];
	}
	std::cin >> M;
	std::vector<int> u(M), v(M);
	for (int i = 0; i < M; i++) {
		std::cin >> u[i] >> v[i];
		--u[i]; --v[i];
	}
	cout << solve(N, a, b, M, u, v) << endl;
	return 0;
}
