// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL n, t, next, tail = 0, ans = 0;
	cin >> n >> t;
	for (LL i = 0; i < n; ++i) {
		cin >> next;
		ans += t - max(0LL, tail - next);
		tail = next + t;
	}
	cout << ans << endl;
	return 0;
}
