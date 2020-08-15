// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	LL x, k, d;
	cin >> x >> k >> d;
	if (x < 0) x = -x;
	LL r = min(k, x / d);
	x -= r * d;
	LL ans = (k - r) % 2 ? abs(x - d) : x;
	cout << ans << endl;
	return 0;
}
