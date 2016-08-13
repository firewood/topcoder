// D.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int a = -1, b = -1;
	for (int i = 1; i != s.length(); ++i) {
		if (s[i - 1] == s[i]) {
			a = i, b = i + 1;
			break;
		}
		if (i > 1 && s[i - 2] == s[i]) {
			a = i - 1, b = i + 1;
			break;
		}
	}
	cout << a << " " << b << endl;
	return 0;
}
