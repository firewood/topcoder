// B.

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	cout << s.front() << (s.length() - 2) << s.back() << endl;
	return 0;
}
