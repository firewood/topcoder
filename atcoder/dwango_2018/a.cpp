// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	bool ans = s[0] == s[2] && s[1] == s[3];
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
