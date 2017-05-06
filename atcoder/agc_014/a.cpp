// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	for (ans = 0; ans < 1000000; ++ans) {
		if ((a % 2) || (b % 2) || (c % 2)) {
			break;
		}
		int pa = a, pb = b, pc = c;
		a = pb / 2 + pc / 2;
		b = pa / 2 + pc / 2;
		c = pa / 2 + pb / 2;
	}
	cout << (ans >= 1000000 ? -1 : ans) << endl;
	return 0;
}
