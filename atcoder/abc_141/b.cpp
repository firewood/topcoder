// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int len = s.length();
	bool ans = true;
	for (int i = 0; i < len; ++i) {
		if (i & 1) {
			if (s[i] == 'R') {
				ans = false;
			}
		} else {
			if (s[i] == 'L') {
				ans = false;
			}
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
