// A. Fairness

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL a, b, c, k;
	cin >> a >> b >> c >> k;
	LL mx = k % 2;
	for (LL i = 0; i < mx; ++i) {
		LL p = b + c, q = a + c, r = a + b;
		a = p, b = q, c = r;
	}
	LL ans = a - b;
	if (abs(ans) > 1e18) {
		cout << "Unfair" << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}
