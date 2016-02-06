#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	for (int i = 0; i < (int)s.length(); ++i) {
		s[i] ^= 0x20;
	}
	cout << s << endl;
	return 0;
}
