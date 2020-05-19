// C.

#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	cout.precision(20);
	double a, b, h, m, r;
	cin >> a >> b >> h >> m;
	r = ((h+m/60) / 12.0) * 2.0 * M_PI;
	double hx = a * sin(r), hy = a * cos(r);
	r = (m / 60.0) * 2.0 * M_PI;
	double mx = b * sin(r), my = b * cos(r);
	double ans = sqrt((hx - mx) * (hx - mx) + (hy - my) * (hy - my));
	cout << ans << endl;
	return 0;
}
