// Google Code Jam 2019 Qualification Round
// Problem A. Foregone Solution

#include <iostream>
#include <sstream>

using namespace std;

string solve(string s) {
	string a, b;
	for (char c : s) {
		string x = b.empty() ? "" : "0";
		if (c == '4') {
			c = '2';
			x = "2";
		}
		a += c;
		b += x;
	}
	return a + " " + b;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string s;
		cin >> s;
		string ans = solve(s);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
