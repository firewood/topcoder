// Google Code Jam 2022 Qualification Round
// Problem B. 3D Printing (13pts)

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solve(vector<vector<int>> c) {
	vector<int> ans;
	int r = 1000000;
	for (int j = 0; j < c[0].size(); ++j) {
		int mn = r;
		for (int i = 0; i < c.size(); ++i) {
			mn = min(mn, c[i][j]);
		}
		ans.emplace_back(mn);
		r -= mn;
	}
	return r == 0 ? ans : vector<int>();
}

int main(int argc, char *argv[]) {
	int T, X, Y;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		vector<vector<int>> c(3, vector<int>(4));
		for (int i = 0; i < c.size(); ++i) {
			for (int j = 0; j < c[0].size(); ++j) {
				cin >> c[i][j];
			}
		}
		vector<int> ans = solve(c);
		cout << "Case #" << t << ":";
		if (ans.empty()) {
			cout << " IMPOSSIBLE" << endl;
		} else {
			for (auto x : ans) {
				cout << " " << x;
			}
			cout << endl;
		}
	}
	return 0;
}
