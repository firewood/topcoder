#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	for (int i = 0; i < (int)s.length(); ++i) {
		char c = (s[i] - 'A' + 26000 - i - 1) % 26 + 'A';
		cout << c;
	}
	cout << endl;
	return 0;
}
