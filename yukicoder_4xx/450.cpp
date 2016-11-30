#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <cstdio>

using namespace std;

int main(int argc, char *argv[]) {
	cout.precision(10);
	long double vl, vr, d, w, ans = 0;
	cin >> vl >> vr >> d >> w;
	ans = d * w / (vl + vr);
	cout << ans << endl;
	return 0;
}
