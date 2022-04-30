// Google Code Jam 2022 Qualification Round
// Problem A. Punched Cards (11pts)

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> solve(int r, int c) {
	vector<string> ans(2 * r + 1, string(c * 2 + 1, '+'));
	for (int i = 0; i <= r; ++i) {
		for (int j = 0; j <= c; ++j) {
			if (j < c) {
				ans[i * 2][j * 2 + 1] = '-';
			}
			if (i < r) {
				ans[i * 2 + 1][j * 2] = '|';
			}
			if (i < r && j < c) {
				ans[i * 2 + 1][j * 2 + 1] = '.';
			}
		}
	}
	ans[0][0] = '.';
	ans[0][1] = '.';
	ans[1][0] = '.';
	return ans;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int r, c;
		cin >> r >> c;
		vector<string> ans = solve(r, c);
		cout << "Case #" << t << ":" << endl;
		for (auto x : ans) {
			cout << x << endl;
		}
	}
	return 0;
}
