// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	long double n, m, d;
	cin >> n >> m >> d;
	long double x = (n - d);
	long double y = (d < 1 ? 1.0 : 2.0) * x / n;
	long double ans = (m - 1) * y / n;
	printf("%.7f\n", (double)ans);
	return 0;
}
