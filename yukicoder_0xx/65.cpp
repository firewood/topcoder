#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

double memo[32];

int K;

double e(int x) {
	if (x >= K) {
		return 0;
	}
	if (x >= K - 1) {
		return 1;
	}
	double &r = memo[x];
	if (r > 0) {
		return r;
	}
	r = e(x + 1) / 6 + e(x + 2) / 6 + e(x + 3) / 6 + e(x + 4) / 6 + e(x + 5) / 6 + e(x + 6) / 6 + 1;
	return r;
}

int main(int argc, char *argv[])
{
	cout.precision(12);
	cin >> K;
	for (int i = 0; i < 32; ++i) {
		memo[i] = -1;
	}
	double ans = e(0);
	cout << ans << endl;
	return 0;
}
