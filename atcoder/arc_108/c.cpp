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

typedef pair<int, int> II;

void solve(int N, int M, std::vector<int>& u, std::vector<int>& v, std::vector<int>& c) {
	vector<vector<II>> edges(N);
	vector<int> color(N, -1);
	for (int i = 0; i < M; ++i) {
		edges[u[i]].emplace_back(II(v[i], c[i]));
		edges[v[i]].emplace_back(II(u[i], c[i]));
	}
	vector<int> q;
	q.emplace_back(0);
	color[0] = 1;
	while (!q.empty()) {
		vector<int> nq;
		for (auto from : q) {
			for (auto kv : edges[from]) {
				int to = kv.first, col = kv.second;
				if (color[to] >= 0) continue;
				if (color[from] == col) {
					++col;
				}
				color[to] = col <= N ? col : 1;
				nq.emplace_back(to);
			}
		}
		q = nq;
	}
	for (int i = 0; i < N; ++i) {
		cout << color[i] << endl;
	}
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> u(M), v(M), c(M);
	for (int i = 0; i < M; i++) {
		std::cin >> u[i] >> v[i] >> c[i];
		u[i]--; v[i]--;
	}
	solve(N, M, u, v, c);
	return 0;
}
