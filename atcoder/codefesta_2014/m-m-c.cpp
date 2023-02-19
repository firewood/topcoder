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

LD solve(LD p, int64_t n) {
	LD ans = 0;
	while (n > 0) {
		if (n & 1) {
			ans = ans * (1 - p) + (1 - ans) * p;
		}
		p = 2 * p * (1 - p);
		n >>= 1;
	}
	return ans;
}

int main() {
	cout.precision(20);
	LD p;
	int64_t n;
	std::cin >> p >> n;
	cout << solve(p, n) << endl;
	return 0;
}
