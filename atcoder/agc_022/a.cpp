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
	int u[26] = {};
	for (char c : s) {
		++u[c - 'a'];
	}
	string ans;
	if (s.length() < 26) {
		for (int i = 0; i < 26; ++i) {
			if (!u[i]) {
				ans = s + char('a' + i);
				break;
			}
		}
	} else {
		for (int i = s.length() - 1; ans.empty() && i >= 0; --i) {
			--u[s[i] - 'a'];
			for (int j = s[i] - 'a' + 1; j < 26; ++j) {
				if (!u[j]) {
					ans = s.substr(0, i) + char('a' + j);
					break;
				}
			}
		}
	}
	cout << (ans.empty() ? "-1" : ans) << endl;
	return 0;
}
