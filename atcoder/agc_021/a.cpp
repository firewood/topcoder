// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int sum = 0, length = (int)s.length();
	for (int i = 1; i < length; ++i) {
		sum += s[i] - '0';
	}
	if (sum != (length - 1) * 9) {
		sum = (length - 1) * 9 - 1;
	}
	sum += s[0] - '0';
	cout << sum << endl;
	return 0;
}
