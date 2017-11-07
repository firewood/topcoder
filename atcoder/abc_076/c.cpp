// C.

#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	string s, t;
	cin >> s >> t;
	string ans;
	for (int i = s.length() - t.length(); i >= 0; --i) {
		bool ok = true;
		for (int j = 0; j < (int)t.length(); ++j) {
			if (s[i + j] != t[j] && s[i + j] != '?') {
				ok = false;
			}
		}
		if (ok) {
			string c = s.substr(0, i) + t + s.substr(i + t.length());
			replace(c.begin(), c.end(), '?', 'a');
			if (ans.empty() || ans > c) {
				ans = c;
			}
		}
	}
	cout << (ans.empty() ? "UNRESTORABLE" : ans) << endl;
	return 0;
}
