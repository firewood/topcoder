#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int check(string s) {
	int r = 1;
	int len = s.length();
	for (int i = 1; i < len; ++i) {
		for (int j = 1; j <= i && i + j < len; ++j) {
			if (s[i - j] != s[i + j]) {
				break;
			}
			r = max(r, j * 2 + 1);
		}
		for (int j = 1; j <= i && i + j - 1 < len; ++j) {
			if (s[i - j] != s[i + j - 1]) {
				break;
			}
			r = max(r, j * 2);
		}
	}
	return r;
}

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int ans = max(check(s.substr(0, s.length() - 1)), check(s.substr(1)));
	cout << ans << endl;
	return 0;
}
