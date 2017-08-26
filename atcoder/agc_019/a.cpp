// A. 

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL q, h, s, d, n;
	cin >> q >> h >> s >> d >> n;
	LL a = n / 2;
	LL b = min(min(q * 8, h * 4), min(s * 2, d));
	LL ans = a * b;
	a = n - a * 2;
	b = min(min(q * 4, h * 2), s);
	ans += a * b;
	cout << ans << endl;
	return 0;
}
