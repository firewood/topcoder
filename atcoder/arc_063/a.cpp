// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int c[3];
	cin >> c[0] >> c[1] >> c[2];
	sort(c, c + 3);
	cout << ((c[0] + c[1] == c[2]) ? "Yes" : "No") << endl;
	return 0;
}
