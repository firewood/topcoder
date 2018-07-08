// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int w;
	cin >> w;
	int len = (int)s.length();
	for (int i = 0; i < len; i += w) {
		cout << s[i];
	}
	cout << endl;
	return 0;
}
