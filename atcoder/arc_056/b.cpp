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

void solve(int N, int M, int S, std::vector<int> &u, std::vector<int> &v) {
    vector<vector<int>> edges(N);
    for (int i = 0; i < M; i++) {
        edges[u[i]].emplace_back(v[i]);
        edges[v[i]].emplace_back(u[i]);
    }
    priority_queue<II> q;
    vector<int> cost(N);
    q.emplace(II(S, S));
    while (!q.empty()) {
        II top = q.top();
        q.pop();
        cost[top.second] = top.first;
        for (int node : edges[top.second]) {
            int c = min(top.first, node);
            if (c > cost[node]) {
                cost[node] = c;
                q.emplace(II(c, node));
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (cost[i] >= i) {
            cout << i + 1 << endl;
        }
    }
}

int main() {
#if DEBUG
	freopen("in_1.txt", "r", stdin);
#endif

    int N, M, S;
	std::cin >> N >> M >> S;
    --S;
	std::vector<int> u(M), v(M);
	for (int i = 0; i < M; i++) {
		std::cin >> u[i] >> v[i];
        --u[i]; --v[i];
	}
	solve(N, M, S, u, v);
	return 0;
}
