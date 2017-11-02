// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string a, b, c;
	cin >> a >> b;
	for (int i = 0; i < (int)b.length(); ++i) {
		c += a[i];
		c += b[i];
	}
	if (a.length() != b.length()) {
		c += a.back();
	}
	cout << c << endl;
	return 0;
}
