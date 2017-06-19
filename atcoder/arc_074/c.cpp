// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

LL get_min(LL a, LL b) {
	LL c = a / 3;
	LL m = (a - c * 2 - (a - c) / 2) * b;
	for (LL i = 1; i <= a / 2; ++i) {
		LL p = i * b;
		LL q = (a - i) * (b / 2);
		LL r = (a - i) * (b - b / 2);
		LL s = min(min(p, q), r);
		LL t = max(max(p, q), r);
		m = min(m, t - s);
	}
	return m;
}

int main(int argc, char *argv[])
{
	LL h, w;
	cin >> h >> w;
	LL ans = min(get_min(h, w), get_min(w, h));
	cout << ans << endl;
	return 0;
}
