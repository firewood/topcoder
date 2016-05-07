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
	int ans = c / min(a, b);
	cout << ans << endl;
	return 0;
}
