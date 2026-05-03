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
const string YES = "Yes";
const string NO = "No";

bool detect_cycle(const vector<vector<int>> &g) {
	size_t n = g.size();
	vector<bool> visited(n, false), finished(n, false);
	auto dfs = [&](auto dfs_, int x) -> bool {
		if (visited[x]) return false;
		visited[x] = true;
		for (int y : g[x]) {
			if (finished[y]) continue;
			if (visited[y] || dfs_(dfs_, y)) return true;
		}
		finished[x] = true;
		return false;
	};
	for (int i = 0; i < int(n); ++i) {
		if (dfs(dfs, i)) return true;
	}
	return false;
}

bool solve(int64_t N, int64_t M, vector<int64_t> U, vector<int64_t> V, int64_t W, vector<string> S) {
	vector<vector<int>> edges(N * W);
	auto add_edge = [&](int a, int b) {
		for (int64_t w = 0; w < W; ++w) {
			int nw = (w + 1) % W;
			if (S[a][w] == 'o' && S[b][nw] == 'o') {
				edges[a * W + w].emplace_back(b * W + nw);
			}
		}
	};
	for (int64_t i = 0; i < M; ++i) {
		add_edge(U[i], V[i]);
		add_edge(V[i], U[i]);
	}
	for (int64_t i = 0; i < N; ++i) {
		add_edge(i, i);
	}
	return detect_cycle(edges);
}

void process_case() {
	int64_t N, M, W;
	cin >> N >> M;
	vector<int64_t> U(M), V(M);
	for (int64_t i = 0; i < M; ++i) {
		cin >> U[i] >> V[i];
		--U[i];
		--V[i];
	}
	cin >> W;
	vector<string> S(N);
	for (int64_t i = 0; i < N; ++i) {
		cin >> S[i];
	}
	auto ans = solve(N, M, U, V, W, S);
	cout << (ans ? YES : NO) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		process_case();
	}
}
