// A.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	const char *s[] = { "Christmas Eve Eve Eve", "Christmas Eve Eve", "Christmas Eve", "Christmas" };
	int d;
	cin >> d;
	cout << s[d - 22] << endl;
	return 0;
}
