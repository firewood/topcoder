#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

typedef pair<int, int> II;

vector<vector<int>> edges;
vector<int> visited;

int st, ed, max_dist;

// 木の直径
II dfs(int n) {
	visited[n] = 1;
	vector<II> v;
	for (int next : edges[n]) {
		if (!visited[next]) {
			v.emplace_back(dfs(next));
		}
	}
	sort(v.rbegin(), v.rend());
	if (v.size() >= 2) {
		int dist = v[0].first + v[1].first;
		if (dist > max_dist) {
			max_dist = dist;
			st = v[0].second;
			ed = v[1].second;
		}
	}
	if (v.empty()) {
		return { 1, n };
	}
	return { v[0].first + 1, v[0].second };
}

void solve(int N, std::vector<int> &A, std::vector<int> &B) {
	edges = vector<vector<int>>(N);
	max_dist = -1;
	for (int i = 0; i < A.size(); ++i) {
		edges[A[i]].emplace_back(B[i]);
		edges[B[i]].emplace_back(A[i]);
	}
	visited = vector<int>(N);
	II r = dfs(0);
	if (r.first > max_dist) {
		st = 0;
		ed = r.second;
	}
	cout << st + 1 << " " << ed + 1 << endl;
}

int main() {
    int N;
	std::cin >> N;
	std::vector<int> A(N - 1), B(N - 1);
	for (int i = 0; i < N-1; i++) {
		std::cin >> A[i] >> B[i];
		A[i]--, B[i]--;
	}
	solve(N, A, B);
	return 0;
}
