// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b;
	cin >> a >> b;
	int ans = b - a - (a < 0 && b > 0);
	cout << ans << endl;
	return 0;
}
