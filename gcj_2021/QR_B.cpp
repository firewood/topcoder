// Google Code Jam 2021 Qualification Round
// Problem B. Moons and Umbrellas (5pts, 11pts, 1pts)

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int X, int Y, string s) {
	int ans = 0;
	vector<int> dp({ s[0] == 'J' ? 1 << 30 : 0, s[0] == 'C' ? 1 << 30 : 0 });
	for (int i = 1; i < (int)s.length(); ++i) {
		vector<int> next(2, 1 << 30);
		if (s[i] == 'C' || s[i] == '?') {
			next[0] = min(dp[0], dp[1] + Y);
		}
		if (s[i] == 'J' || s[i] == '?') {
			next[1] = min(dp[1], dp[0] + X);
		}
		dp = next;
	}
	return min(dp[0], dp[1]);
}

int main(int argc, char *argv[]) {
	int T, X, Y;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string s;
		cin >> X >> Y >> s;
		int ans = solve(X, Y, s);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
