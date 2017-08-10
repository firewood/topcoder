// A.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int p[3];
	cin >> p[0] >> p[1] >> p[2];
	sort(p, p + 3);
	cout << (p[0] + p[1]) << endl;
	return 0;
}
