// C.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int n;
int target[3];
int fragment[8];

int dfs(int i, int used) {
	if (i >= 3) return 0;
	int min_cost = 1 << 30;
	int bm = 1 << n;
	for (int t = 1; t < bm; ++t) {
		if (used & t) continue;
		int len = 0, cost = 0;
		for (int i = 0; i < n; ++i) {
			if ((1 << i) & t) {
				if (len) {
					cost += 10;
				}
				len += fragment[i];
			}
		}
		cost += abs(target[i] - len);
		cost += dfs(i + 1, used | t);
		min_cost = min(min_cost, cost);
	}
	return min_cost;
}

int main(int argc, char *argv[]) {
	cin >> n;
	for (int i = 0; i < 3; ++i) {
		cin >> target[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> fragment[i];
	}
	int ans = dfs(0, 0);
	cout << ans << endl;
	return 0;
}
