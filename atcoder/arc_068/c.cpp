// C.

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL x;
	cin >> x;
	LL y = x / 11;
	LL ans = y * 2;
	x -= y * 11;
	if (x > 6) {
		ans += 2;
	} else if (x) {
		++ans;
	}
	cout << ans << endl;
	return 0;
}
