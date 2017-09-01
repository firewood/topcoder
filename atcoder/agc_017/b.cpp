// B.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	bool ans = false;
	for (LL i = 0; i <= (n - 1); ++i) {
		LL p = a + i * c - (n - 1 - i) * c;
		LL q = (d - c) * i;
		LL r = (d - c) * (n - 1 - i);
		if ((p - r) <= b && b <= p + q) {
			ans = true;
			break;
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
