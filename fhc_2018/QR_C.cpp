//
// Facebook Hacker Cup 2018 Qualification Round
// C. 
//

#include <iostream>
#include <sstream>

using namespace std;

bool check(string a, string b) {
	int i = 0, j = 0;
	while (i < (int)a.length()) {
		if (j == b.length()) {
			return false;
		}
		if (a[i] == b[j]) {
			++i, ++j;
			continue;
		}
		if (!i) {
			++j;
		} else {
			i = 0;
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string ans = "Impossible";
		string s;
		cin >> s;
		int len = (int)s.length();
		string x;
		for (int i = 0; i < len; ++i) {
			x += s[i];
			string y = x + s;
			if (!check(s, y)) {
				ans = y;
				break;
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
