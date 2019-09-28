// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	while (true) {
		int n = -1, m = -1;
		cin >> n >> m;
		if (n <= 0) break;
		int bm = 1 << n;
		vector<int> cost[2];
		cost[0] = vector<int>(bm, 1 << 30);
		cost[0][0] = 0;
		for (int i = 0; i < m; ++i) {
			int prev = i & 1, curr = prev ^ 1;
			int a, b, c, f = 0;
			cin >> a >> b;
			for (int j = 0; j < b; ++j) {
				cin >> c;
				f |= 1 << (c - 1);
			}
			cost[curr] = cost[prev];
			for (int j = 0; j < bm; ++j) {
				cost[curr][j | f] = min(cost[curr][j | f], a + cost[prev][j]);
			}
		}
		int ans = cost[m & 1][bm - 1];
		cout << (ans < (1 << 30) ? ans : -1) << endl;
	}
	return 0;
}
