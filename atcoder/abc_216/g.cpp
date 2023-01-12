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

vector<int> solve(int N, int M, std::vector<int> L, std::vector<int> R, std::vector<int> X) {
	vector<int> ans(N), values(N + 1, 1 << 29);
	vector<vector<II>> edges(N + 1);
	for (int i = 0; i < N; ++i) {
		edges[i].emplace_back(i + 1, 1);
		edges[i + 1].emplace_back(i, 0);
	}
	for (int i = 0; i < M; ++i) {
		edges[L[i] - 1].emplace_back(R[i], R[i] - L[i] + 1 - X[i]);
	}
	values[0] = 0;
	priority_queue<II, vector<II>, greater<>> q;
	q.emplace(0, 0);
	while (!q.empty()) {
		int co = q.top().first, current = q.top().second;
		q.pop();
		if (values[current] != co) continue;
		for (auto [node, cost] : edges[current]) {
			if (values[node] > values[current] + cost) {
				values[node] = values[current] + cost;
				q.emplace(values[node], node);
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		ans[i] = 1 - (values[i + 1] - values[i]);
	}
	return ans;
}

int main() {
	int N, M;
	std::cin >> N >> M;
	std::vector<int> L(M), R(M), X(M);
	for (int i = 0; i < M; i++) {
		std::cin >> L[i] >> R[i] >> X[i];
	}
	vector<int> ans = solve(N, M, L, R, X);
	for (size_t i = 0; i < ans.size(); ++i) {
		if (i) cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
