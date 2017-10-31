// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string a, b;
	cin >> a >> b;
	if (a == b) {
		cout << "EQUAL" << endl;
	} else if (a.length() > b.length()) {
		cout << "GREATER" << endl;
	} else if (a.length() < b.length()) {
		cout << "LESS" << endl;
	} else {
		cout << (a > b ? "GREATER" : "LESS") << endl;
	}
	return 0;
}
