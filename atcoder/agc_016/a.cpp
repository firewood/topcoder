// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int ans = 1 << 30, n = (int)s.length();
	for (char c = 'a'; c <= 'z'; ++c) {
		if (s.find(c) != string::npos) {
			string t = s;
			for (int i = 0; ; ++i) {
				if (count(t.begin(), t.end(), c) == t.length()) {
					ans = min(ans, i);
					break;
				}
				string next;
				for (int j = 0; next.length() < (t.length() - 1); ++j) {
					if (t[j] == c || t[j + 1] == c) {
						next += c;
					} else {
						next += t[j];
					}
				}
				t = next;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
