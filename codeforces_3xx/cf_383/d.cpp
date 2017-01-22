// D. Arpa's weak amphitheater and Mehrdad's valuable Hoses

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

struct UnionFind {
	std::vector<int> _parent;
	std::vector<int> _size;
	UnionFind(int size) : _parent(size, -1), _size(size, 1) { }
	void unite(int a, int b) {
		int ra = root(a), rb = root(b); if (ra == rb) { return; }
		if (_size[ra] >= _size[rb]) { _parent[rb] = ra, _size[ra] += _size[rb]; } else { _parent[ra] = rb, _size[rb] += _size[ra]; }
	}
	int root(int a) {
		int p = _parent[a];
		if (p < 0) { return a; }
		while (_parent[p] >= 0) { p = _parent[p]; }
		return _parent[a] = p;
	}
	int size(int a) { return _size[root(a)]; }
};

int main(int argc, char *argv[])
{
	int N, M, W, w[1000], b[1000], gw[1000] = {}, gb[1000] = {};
	UnionFind uf(1000);
	cin >> N >> M >> W;
	for (int i = 0; i < N; ++i) {
		cin >> w[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < M; ++i) {
		int x, y;
		cin >> x >> y;
		uf.unite(x - 1, y - 1);
	}
	vector<int> g[1000];
	for (int i = 0; i < N; ++i) {
		int r = uf.root(i);
		g[r].push_back(i);
		gw[r] += w[i];
		gb[r] += b[i];
	}
	int dp[1002] = {};
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		if (i == uf.root(i)) {
			for (int j = 1000; j > 0; --j) {
				for (int k : g[i]) {
					if (j >= w[k] && dp[j - w[k]] >= 0) {
						dp[j] = max(dp[j], dp[j - w[k]] + b[k]);
					}
					if (j >= gw[i] && dp[j - gw[i]] >= 0) {
						dp[j] = max(dp[j], dp[j - gw[i]] + gb[i]);
					}
				}
			}
		}
	}
	int ans = *max_element(dp, dp + W + 1);
	cout << ans << endl;
	return 0;
}
