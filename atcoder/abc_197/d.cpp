#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long double LD;

int main() {
	cout.precision(20);
	LD N, x0, y0, x2, y2;
	cin >> N >> x0 >> y0 >> x2 >> y2;
	LD cx = (x0 + x2) / 2, cy = (y0 + y2) / 2;
	LD dx = x0 - cx, dy = y0 - cy;
	LD r = atan2(dy, dx) + (2 * M_PI) / N;
	LD d = sqrt(dx * dx + dy * dy);
	LD x1 = cx + cos(r) * d, y1 = cy + sin(r) * d;
	cout << x1 << " " << y1 << endl;
	return 0;
}
