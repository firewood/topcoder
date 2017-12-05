// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s[3];
	cin >> s[0] >> s[1] >> s[2];
	int p = 0;
	while (!s[p].empty()) {
		int n = s[p][0] - 'a';
		s[p] = s[p].substr(1);
		p = n;
	}
	cout << ("ABC"[p]) << endl;
	return 0;
}
