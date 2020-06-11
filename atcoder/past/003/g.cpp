// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;

int main() {
	int n, gx, gy, a, b;
	cin >> n >> gx >> gy;
	vector<vector<int>> vis(404, vector<int>(404));
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		vis[a + 202][b + 202] = -1;
	}
	vector<II> q;
	q.emplace_back(II(0, 0));
	vis[202][202] = 1;
	int ans = 0;
	while (!q.empty()) {
		vector<II> nq;
		for (auto kv : q) {
			int x = kv.first, y = kv.second;
			if (x == gx && y == gy) {
				cout << ans << endl;
				return 0;
			}
			for (int i = -1; i <= 1; ++i) {
				for (int j = -1; j <= 1; ++j) {
					if (i == 0 && j == 0) continue;
					if (i == -1 && j == -1) continue;
					if (i == 1 && j == -1) continue;
					int nx = x + i, ny = y + j;
					if (nx < -201 || nx > 201 || ny < -201 || ny > 201) continue;
					if (vis[nx + 202][ny + 202]) continue;
					vis[nx + 202][ny + 202] = 1;
					nq.emplace_back(II(nx, ny));
				}
			}
		}
		++ans;
		q = nq;
	}
	cout << "-1" << endl;
	return 0;
}
