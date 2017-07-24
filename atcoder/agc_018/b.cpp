// B.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

typedef pair<int, int> II;
typedef vector<int> IntVec;
typedef map<int, IntVec> IntVecMap;

int main(int argc, char *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<int> a[300];
	IntVecMap g;
	int d[300] = {};
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int x;
			cin >> x;
			a[i].push_back(x-1);
		}
		g[a[i][0]].push_back(i);
	}

	int ans = n;
	for (int i = 0; i < m-1; ++i) {
		int mi = -1;
		int mx = 0;
		for (auto &kv : g) {
			if (kv.second.size() > mx) {
				mi = kv.first;
				mx = kv.second.size();
			}
		}
		ans = min(ans, mx);

		IntVec v = g[mi];
		g.erase(mi);
		d[mi] = 1;
		for (int x : v) {
			for (int y : a[x]) {
				if (!d[y]) {
					g[y].push_back(x);
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
