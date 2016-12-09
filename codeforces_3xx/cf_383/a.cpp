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
	LL n;
	cin >> n;
	LL ans = 1, x = 8;
	for (LL i = 1; i <= n; i *= 2) {
		if (n & i) {
			ans = (ans * x) % 10;
		}
		x = (x * x) % 10;
	}
	cout << ans << endl;
	return 0;
}
