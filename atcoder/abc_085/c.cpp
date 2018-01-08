// C.

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	int n, y;
	cin >> n >> y;
	y /= 1000;
	int ma = y / 10;
	int a, b, c;
	for (a = 0; a <= ma; ++a) {
		int rn = n - a;
		int ry = y - a * 10;
		b = (ry - rn) / 4;
		c = rn - b;
		if (b >= 0 && c >= 0 && (a + b + c) == n && (a * 10 + b * 5 + c) == y) {
			break;
		}
	}
	if (a > ma) {
		a = b = c = -1;
	}
	cout << a << " " << b << " " << c << endl;
	return 0;
}
