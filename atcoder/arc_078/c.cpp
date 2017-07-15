// C.

#include <iostream>
#include <list>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL n, a[200000], sum = 0, x = 0, ans = 1LL << 60;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i < n-1; ++i) {
		x += a[i];
		ans = min(ans, abs(sum - x - x));
	}
	cout << ans << endl;
	return 0;
}
