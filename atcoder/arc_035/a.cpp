// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int len = s.length();
	bool possible = true;
	for (int i = 0; i < len / 2; ++i) {
		char a = s[i], b = s[len - i - 1];
		if (a != b && a != '*' && b != '*') {
			possible = false;
			break;
		}
	}
	cout << (possible ? "YES" : "NO") << endl;
	return 0;
}
