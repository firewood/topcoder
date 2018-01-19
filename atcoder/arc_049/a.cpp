// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	for (int i = 0; i < 4; ++i) {
		int pos;
		cin >> pos;
		s = s.substr(0, pos + i) + "\"" + s.substr(pos + i);
	}
	cout << s << endl;
	return 0;
}
