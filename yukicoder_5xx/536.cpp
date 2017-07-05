#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	if (s.substr(s.length() - 2).compare("ai") == 0) {
		s = s.substr(0, s.length() - 2) + "AI";
	} else {
		s += "-AI";
	}
	cout << s << endl;
	return 0;
}
