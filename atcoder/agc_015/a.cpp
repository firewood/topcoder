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
	LL n, a, b;
	cin >> n >> a >> b;
	LL low = n * a + (b - a);
	LL high = n * b + (a - b);
	LL ans = max(0LL, high - low + 1);
	if (n <= 1 && a != b) {
		ans = 0;
	}
	cout << ans << endl;
	return 0;
}
