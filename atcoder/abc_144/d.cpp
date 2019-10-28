// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long double LD;

int main(int argc, char* argv[]) {
	cout.precision(10);
	while (true) {
		LD a = -1, b = -1, x = -1, ans;
		cin >> a >> b >> x;
		if (a <= 0 || b <= 0 || x <= 0) break;
		LD f = a * a * b, h = f * 0.5;
		if (x >= f) {
			ans = 0;
		} else if (x >= h) {
			LD r = f - x, v = r / (a * a) * 2;
			ans = 90 - atan2(a, v) / (2 * M_PI) * 360;
		} else {
			LD v = x / (a * b) * 2;
			ans = atan2(b, v) / (2 * M_PI) * 360;
		}
		cout << ans << endl;
	}
	return 0;
}
