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

long long solve(long long a, long long b, long long x, long long y) {
	if (a > b) {
		return min((a - b - 1) * y + x, ((a - b) * 2 - 1) * x);
	} else {
		return min((b - a) * y + x, ((b - a) * 2 + 1) * x);
	}
}

int main() {
	long long a, b, x, y;
	std::cin >> a >> b >> x >> y;
	cout << solve(a, b, x, y) << endl;
	return 0;
}
