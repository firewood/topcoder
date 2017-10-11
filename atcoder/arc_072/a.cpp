// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	string a, b, c;
	cin >> a >> b >> c;
	string ans = string(1, toupper(a[0])) + string(1, toupper(b[0])) + string(1, toupper(c[0]));
	cout << ans << endl;
	return 0;
}
