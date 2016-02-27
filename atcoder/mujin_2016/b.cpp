// B.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

typedef long double LD;

int main(int argc, char *argv[])
{
	cout.precision(10);
	LD a, b, c, r, m, x, ans;
	cin >> a >> b >> c;
	m = r = a + b + c;
	if (a >= b + c) {
		m = a - b - c;
	} else if (b >= a + c) {
		m = b - a - c;
	} else if (c >= a + b) {
		m = c - a - b;
	} else {
		m = max(0.0L, a + b - c);
		x = fabs(a - b);
		m = min(m, max(0.0L, x - c));
	}
	ans = (r * r - m * m) * M_PI;
	cout << ans << endl;
	return 0;
}
