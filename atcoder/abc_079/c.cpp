// C.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0', d = s[3] - '0';
	for (int i = 0; i < 8; ++i) {
		int e = a + ((i & 1) ? b : -b) + ((i & 2) ? c : -c) + ((i & 4) ? d : -d);
		if (e == 7) {
			cout << a << ((i & 1) ? "+" : "-") << b << ((i & 2) ? "+" : "-") << c << ((i & 4) ? "+" : "-") << d << "=7" << endl;
			break;
		}
	}
	return 0;
}
