// Google Code Jam 2017 Qualification Round
// Problem A. Oversized Pancake Flipper

#include <iostream>
#include <sstream>

using namespace std;

int solve(string s, int k) {
	if (s.empty()) {
		return 0;
	}
	if (s[0] == '+') {
		return solve(s.substr(1), k);
	}
	if (k > s.length()) {
		return -1;
	}
	for (int i = 0; i < k; ++i) {
		s[i] = s[i] == '+' ? '-' : '+';
	}
	int r = solve(s.substr(1), k);
	return r < 0 ? -1 : 1 + r;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string s;
		int k;
		cin >> s >> k;
		int ans = solve(s, k);
		if (ans < 0) {
			cout << "Case #" << t << ": IMPOSSIBLE" << endl;
		} else {
			cout << "Case #" << t << ": " << ans << endl;
		}
	}
	return 0;
}
