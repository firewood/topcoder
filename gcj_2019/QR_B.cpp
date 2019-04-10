// Google Code Jam 2019 Qualification Round
// Problem B. You Can Go Your Own Way

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string solve(int n, string s) {
	string ans;
	for (char c : s) {
		ans += c == 'E' ? 'S' : 'E';
	}
	return ans;
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
