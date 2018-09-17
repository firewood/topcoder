// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s, t;
	cin >> s >> t;
	string u = s + s;
	bool ans = false;
	for (int i = 0; i < (int)s.length(); ++i) {
		if (u.substr(i, s.length()) == t) {
			ans = true;
			break;
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
