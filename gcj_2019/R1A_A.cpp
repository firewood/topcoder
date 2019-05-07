// Google Code Jam 2019 Round 1A
// Problem A. Pylons

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int, int> II;

vector<II> solve(int r, int c) {
	vector<II> res(r * c);
	int used[20][20];
	for (int i = 0; i < 10000; ++i) {
		memset(used, 0, sizeof(used));
		int px = -1, py = -1, j;
		for (j = r * c - 1; j >= 0; --j) {
			int x, y, k;
			for (k = 2000; k > 0; --k) {
				x = rand() % c;
				y = rand() % r;
				if (!used[y][x] && x != px && y != py && (x + y) != (px + py) && (x - y) != (px - py)) {
					break;
				}
			}
			if (k <= 0) {
				break;
			}
			res[j] = II(y + 1, x + 1);
			used[y][x] = 1;
			px = x;
			py = y;
		}
		if (j < 0) {
			return res;
		}
	}
	return vector<II>();
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int r, c;
		cin >> r >> c;
		vector<II> ans = solve(r, c);
		cout << "Case #" << t << ": ";
		if (ans.empty()) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << "POSSIBLE" << endl;
			for (auto kv : ans) {
				cout << kv.first << " " << kv.second << endl;
			}
		}
	}
	return 0;
}
