// E.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int e = a | b, f = c ^ d, g = b & c, h = a | d;
	int i = e & f, j = g ^ h;
	int ans = i | j;
	cout << ans << endl;
	return 0;
}
