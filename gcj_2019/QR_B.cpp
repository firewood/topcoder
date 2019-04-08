// Google Code Jam 2019 Qualification Round
// Problem B. You Can Go Your Own Way

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string solve(int n, string s) {
	if (s[0] == 'E' && s.back() == 'S') {
		return string(n - 1, 'S') + string(n - 1, 'E');
	}
	if (s[0] == 'S' && s.back() == 'E') {
		return string(n - 1, 'E') + string(n - 1, 'S');
	}
	if (s[0] == 'E' && s.back() == 'E') {
		int prev = 0, row = 0;
		for (char c : s) {
			if (c == 'S') {
				++row;
				if (prev == c) {
					return string(row - 1, 'S') + string(n - 1, 'E') + string(n - row, 'S');
				}
			}
			prev = c;
		}
	}
	if (s[0] == 'S' && s.back() == 'S') {
		int prev = 0, col = 0;
		for (char c : s) {
			if (c == 'E') {
				++col;
				if (prev == c) {
					return string(col - 1, 'E') + string(n - 1, 'S') + string(n - col, 'E');
				}
			}
			prev = c;
		}
	}
	return "";
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string ans = solve(n, s);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
