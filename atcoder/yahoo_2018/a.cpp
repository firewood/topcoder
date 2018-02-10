// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	bool ans = s[0] == 'y'&&s[1] == 'a'&&s[2] == 'h'&&s[3] == s[4];
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
