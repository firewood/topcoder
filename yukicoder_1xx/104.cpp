#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int pos = 0;
	for (int i = 0; i < (int)s.length(); ++i) {
		pos *= 2;
		pos += s[i] == 'R';
	}
	pos += (1 << s.length());
	cout << pos << endl;
	return 0;
}
