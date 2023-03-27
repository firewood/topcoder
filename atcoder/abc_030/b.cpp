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

LD solve(int n, int m) {
	LD a = (((n % 12) + LD(m) / 60) / 12) * 360, b = LD(m) / 60 * 360, ans = abs(b - a);
	return ans >= 180 ? 360 - ans : ans;
}

int main() {
	cout.precision(20);
	int n, m;
	std::cin >> n >> m;
	cout << solve(n, m) << endl;
	return 0;
}
