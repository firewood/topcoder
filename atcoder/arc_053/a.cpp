// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int h, w;
	cin >> h >> w;
	int ans = h * (w - 1) + (h - 1) * w;
	cout << ans << endl;
	return 0;
}
