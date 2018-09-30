// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	string n;
	cin >> n;
	int len = (int)n.length();
	string x(len, n[0]);
	string ans(len, n[0] + (n > x));
	cout << ans << endl;
	return 0;
}
