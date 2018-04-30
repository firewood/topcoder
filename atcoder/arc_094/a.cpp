// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	cout << (s == "abc" ? "Yes" : "No") << endl;
	return 0;
}
