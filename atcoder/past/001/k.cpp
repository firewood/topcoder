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

typedef long long LL;

void dfs(int node, int &count, vector<int> &offset, vector<int> &counts, vector<vector<int>> &edges) {
    offset[node] = count++;
    for (int next : edges[node]) {
        dfs(next, count, offset, counts, edges);
    }
    counts[node] = count - offset[node];
}

void solve(long long N, std::vector<long long> &p, long long Q, std::vector<long long> &a, std::vector<long long> &b) {
    vector<int> offset(N);
    vector<int> counts(N);
    vector<vector<int>> edges(N);
    int root = 0;
    for (int i = 0; i < N; ++i) {
        if (p[i] < 0) {
            root = i;
        } else {
            edges[p[i]].emplace_back(i);
        }
    }
    int count = 0;
    dfs(root, count, offset, counts, edges);
    for (int i = 0; i < Q; ++i) {
        bool ans = offset[a[i]] > offset[b[i]] && (offset[a[i]] < offset[b[i]] + counts[b[i]]);
        cout << (ans ? "Yes" : "No") << endl;
    }
}

int main() {
#ifdef DEBUG
    freopen("in_2.txt", "r", stdin);
#endif

    long long N;
    std::cin >> N;
    std::vector<long long> p(N);
    for (int i = 0; i < N; i++) {
        std::cin >> p[i];
        p[i]--;
    }
    long long Q;
    std::cin >> Q;
    std::vector<long long> a(Q);
    std::vector<long long> b(Q);
    for (int i = 0; i < Q; i++) {
        std::cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    solve(N, p, Q, a, b);
	return 0;
}
