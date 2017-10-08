// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	bool ans = s.substr(0, 4) == "YAKI";
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
