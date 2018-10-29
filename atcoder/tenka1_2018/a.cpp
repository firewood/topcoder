// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	if (s.length() > 2) {
		reverse(s.begin(), s.end());
	}
	cout << s << endl;
	return 0;
}
