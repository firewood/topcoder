#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int n, len = 0;
	int c[256] = {};
	string s;
	for (int t = 0; t < 2; ++t) {
		len = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> s;
			for (int j = 1; j != s.length(); ++j) {
				c[s[j-1]] = s[j];
			}
			len += s.length();
		}
	}
	string ans = "-1";
	if (len == 1) {
		ans = s;
	} else {
		for (int i = 'A'; i <= 'Z'; ++i) {
			s = "";
			char x = i;
			while (x) {
				s += x;
				x = c[x];
			}
			if (s.length() == len) {
				ans = s;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
