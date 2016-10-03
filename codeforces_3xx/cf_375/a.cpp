// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	a *= 6, b *= 6, c *= 6;
	int ans = 1 << 30;
	for (int i = 0; i <= 600; ++i) {
		ans = min(ans, abs(a - i) + abs(b - i) + abs(c - i));
	}
	cout << ans / 6 << endl;
	return 0;
}
