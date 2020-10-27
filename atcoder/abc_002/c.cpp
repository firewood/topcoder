#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

void solve(long long x_a, long long y_a, long long x_b, long long y_b, long long x_c, long long y_c) {
	long double ans = abs((x_b - x_a) * (y_c - y_a) - (y_b - y_a) * (x_c - x_a)) * 0.5;
	cout << ans << endl;
}

int main() {
	cout.precision(10);
	long long x_a, y_a, x_b, y_b, x_c, y_c;
	std::cin >> x_a >> y_a >> x_b >> y_b >> x_c >> y_c;
	solve(x_a, y_a, x_b, y_b, x_c, y_c);
	return 0;
}
