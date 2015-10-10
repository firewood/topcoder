// A. 

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string delim = "";
	while (true) {
		string s;
		cin >> s;
		if (s.compare("Left") == 0) {
			cout << delim << "<";
		} else if (s.compare("Right") == 0) {
			cout << delim << ">";
		} else if (s.compare("AtCoder") == 0) {
			cout << delim << "A";
		} else {
			break;
		}
		delim = " ";
	}
	cout << endl;
	return 0;
}
