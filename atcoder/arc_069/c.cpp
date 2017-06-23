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
	LL n, m;
	cin >> n >> m;
	LL ans = min(n, m / 2);
	ans += (m - ans * 2) / 4;
	cout << ans << endl;
	return 0;
}
