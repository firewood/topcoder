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

void solve(LD a, LD b, LD d) {
	LD c = sqrt(a * a + b * b), rad = atan2(b, a) + d / 360 * 2 * M_PI;
	LD x = c * cos(rad), y = c * sin(rad);
	cout << x << " " << y << endl;
}

int main() {
	cout.precision(10);
	int64_t a, b, d;
	std::cin >> a >> b >> d;
	solve(a, b, d);
	return 0;
}
