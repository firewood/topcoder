#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;
typedef long double LD;

int main(int argc, char *argv[]) {
	cout.precision(16);
	LD x;
	cin >> x;
	LD ans = 1.6449340668482264;
	for (int n = 10000000; n > 0; --n) {
		ans += 1 / ((x + n) * (x + n));
		ans -= 1 / ((LD)n * n);
	}
	cout << ans << endl;
	return 0;
}
