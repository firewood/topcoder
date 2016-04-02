// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	string a, b;
	cin >> a >> b;
	cout << ((b[0] - a[0]) == 0x20 ? "Yes" : "No") << endl;
	return 0;
}
