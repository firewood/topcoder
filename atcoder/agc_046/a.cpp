// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long double LD;

int main(int argc, char* argv[]) {
	int a, r = 0;
	cin >> a;
	LD p = 0, q = 0;

	for (int t = 1; t < 1000000; ++t) {
		r = (r + a) % 360;
		LD x = cos(2 * M_PI * r / 360) * 65536;
		LD y = sin(2 * M_PI * r / 360) * 65536;
		p += x, q += y;
		if (abs(p) < 0.1 && abs(q) < 0.1) {
			cout << t << endl;
			break;
		}
	}

	return 0;
}
