// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < (int)s.length(); ++i) {
		char c = s[i] - 'A';
		c = (c + n) % 26;
		s[i] = ('A' + c);
	}
	cout << s << endl;
	return 0;
}
