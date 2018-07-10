// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> LLLL;
typedef pair<LL, int> LLI;

int main(int argc, char *argv[]) {
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	--s, --t;
	map<int, LLLL> edges[100000];
	for (int i = 0; i < m; ++i) {
		int u, v, a, b;
		cin >> u >> v >> a >> b;
		--u, --v;
		edges[u][v] = LLLL(a, b);
		edges[v][u] = LLLL(a, b);
	}

	priority_queue<LLI, vector<LLI> > queue;

	LL mcy[100000];
	fill(mcy, mcy + 100000, -(1LL << 60));
	mcy[s] = 0;
	queue.push(LLI(0, s));
	while (queue.size()) {
		LLI top = queue.top();
		queue.pop();
		LL x = top.first;
		LL node = top.second;
		for (auto kv : edges[node]) {
			int next = kv.first;
			LL y = x - kv.second.first;
			if (y > mcy[next]) {
				mcy[next] = y;
				queue.push(LLI(y, next));
			}
		}
	}

	LL mcs[100000];
	fill(mcs, mcs + 100000, -(1LL << 60));
	mcs[t] = 0;
	queue.push(LLI(0, t));
	while (queue.size()) {
		LLI top = queue.top();
		queue.pop();
		LL x = top.first;
		LL node = top.second;
		for (auto kv : edges[node]) {
			int next = kv.first;
			LL y = x - kv.second.second;
			if (y > mcs[next]) {
				mcs[next] = y;
				queue.push(LLI(y, next));
			}
		}
	}

	vector<LL> ans(n + 1);
	for (int i = n - 1; i >= 0; --i) {
		ans[i] = max(ans[i + 1], 1000000000000000LL + mcy[i] + mcs[i]);
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << endl;
	}
	return 0;
}
