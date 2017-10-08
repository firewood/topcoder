// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	string ans = s.substr(0, s.length() - 8);
	cout << ans << endl;
	return 0;
}
