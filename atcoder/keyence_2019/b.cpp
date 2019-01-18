// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int len = (int)s.length();
	bool ans = false;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			if (i + j <= len) {
				string a = s.substr(0, i) + s.substr(i + j, len - i - j);
				if (a == "keyence") {
					ans = true;
				}
			}
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
