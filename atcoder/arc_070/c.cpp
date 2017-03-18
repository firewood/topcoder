// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int X;
	cin >> X;
	int ans = 0, tot = 0;
	for (int t = 1; tot < X; ++t) {
		++ans;
		tot += t;
	}
	cout << ans << endl;
	return 0;
}
