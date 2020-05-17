// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> II;

int main(int argc, char* argv[]) {
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> e(n);
	for (int i = 0; i < m; ++i) {
		cin >> a >> b;
		--a, --b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	vector<int> vis(n, -1);
	vis[0] = 0;
	vector<II> q;
	for (int a : e[0]) {
		q.push_back(II(0, a));
	}
	while (q.size() > 0) {
		vector<II> nq;
		for (auto kv : q) {
			int src = kv.first, dst = kv.second;
			if (vis[dst] >= 0) continue;
			vis[dst] = src + 1;
			for (int a : e[dst]) {
				nq.push_back(II(dst, a));
			}
		}
		q = nq;
	}
	cout << "Yes" << endl;
	for (int i = 1; i < n; ++i) {
		cout << vis[i] << endl;
	}
	return 0;
}
