// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	cout << (s.substr(0, 5) == "MUJIN" ? "Yes" : "No") << endl;
	return 0;
}
