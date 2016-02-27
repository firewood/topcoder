// A. 

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	char c[256] = {};
	c['O'] = c['P'] = c['K'] = c['L'] = 1;
	string s;
	getline(cin, s);
	cout << (c[s[0]] ? "Right" : "Left") << endl;
	return 0;
}
