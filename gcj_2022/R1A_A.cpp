// Google Code Jam 2022 Round 1A
// Problem C. Double or One Thing (10pts, 15pts)

#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string solve(string s) {
	int n = s.length(), prev = 0;
	string ans;
	for (int i = n - 1; i >= 0; --i) {
		char c = s[i];
		if (c < prev) {
			ans += c;
			prev = c + 1;
		} else {
			prev = c;
		}
		ans += c;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main(int argc, char* argv[]) {
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
