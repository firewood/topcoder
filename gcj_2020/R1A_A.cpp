// Google Code Jam 2020 Round 1A
// Problem A. Pattern Matching

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string solve(int n, vector<string> w) {
	string left, right;
	vector<size_t> lpos(n), rpos(n);
	for (int i = 0; i < n; ++i) {
		lpos[i] = w[i].find('*');
		string s = w[i].substr(0, lpos[i]);
		size_t len = min(left.length(), s.length());
		if (left.substr(0, len) != s.substr(0, len)) {
			return "";
		}
		if (s.length() > left.length()) {
			left = s;
		}
		rpos[i] = w[i].rfind('*') + 1;
		s = w[i].substr(rpos[i]);
		len = min(right.length(), s.length());
		if (right.substr(right.length() - len) != s.substr(s.length() - len)) {
			return "";
		}
		if (s.length() > right.length()) {
			right = s;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (size_t j = lpos[i]; j < rpos[i]; ++j) {
			if (w[i][j] != '*') {
				left += w[i][j];
			}
		}
	}
	return left + right;
}

int main(int argc, char* argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		vector<string> w(n);
		for (int i = 0; i < n; ++i) {
			cin >> w[i];
		}
		string ans = solve(n, w);
		cout << "Case #" << t << ": " << (ans.empty() ? "*" : ans) << endl;
	}
	return 0;
}
