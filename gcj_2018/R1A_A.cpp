// Google Code Jam 2018 Round 1A
// Problem A. Waffle Choppers

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

bool solve(int r, int c, int h, int v, vector<string> &b) {
	int sum[256][256] = {};
	for (int i = 0; i < r; ++i) {
		int hs = 0;
		for (int j = 0; j < c; ++j) {
			hs += b[i][j] == '@';
			sum[i + 1][j + 1] = hs + sum[i][j + 1];
		}
	}
	int tot = sum[r][c];
	int cut = tot / ((h+1) * (v+1));
	if (tot != cut * (h+1) * (v+1)) {
		return false;
	}
	int htot = cut * (v + 1);
	int hpos[256] = {};
	int hcnt = 0;
	for (int i = 0; i < r; ++i) {
		int x = sum[i + 1][c] - sum[hpos[hcnt]][c];
		if (x == htot) {
			hpos[++hcnt] = i + 1;
		}
	}
	if (hcnt < (h + 1)) {
		return false;
	}
	int vtot = cut * (h + 1);
	int pos = 0, vcnt = 0;
	for (int j = 0; j < c; ++j) {
		int x = sum[r][j + 1] - sum[r][pos];
		if (x == vtot) {
			for (int i = 1; i <= h; ++i) {
				int y = sum[hpos[i]][j + 1];
				if (y != (vcnt + 1) * i * cut) {
					return false;
				}
			}
			pos = j + 1;
			++vcnt;
		}
	}
	if (vcnt < (v + 1)) {
		return false;
	}
	return true;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int r, c, h, v;
		cin >> r >> c >> h >> v;
		vector<string> b(r);
		for (int i = 0; i < r; ++i) {
			cin >> b[i];
		}
		bool ans = solve(r, c, h, v, b);
		cout << "Case #" << t << ": " << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	}
	return 0;
}
