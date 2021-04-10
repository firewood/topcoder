// Google Code Jam 2021 Qualification Round
// Problem C. Reversort Engineering (7pts, 11pts)

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

vector<int> solve(int N, int C) {
	vector<int> seq(N);
	iota(seq.begin(), seq.end(), 1);
	if (C < N - 1) return {};
	for (int i = N - 1; i >= 1; --i) {
		int r = min(C - (i - 1), N - i + 1);
		if (r < 0) return {};
		reverse(seq.begin() + i - 1, seq.begin() + i - 1 + r);
		C -= r;
	}
	if (C > 0) return {};
	return seq;
}

int main(int argc, char* argv[]) {
	int T, N, C;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> N >> C;
		vector<int> ans = solve(N, C);
		cout << "Case #" << t << ":";
		if (ans.empty()) {
			cout << " IMPOSSIBLE";
		} else {
			for (auto a : ans) {
				cout << " " << a;
			}
		}
		cout << endl;
	}
	return 0;
}
