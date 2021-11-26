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

int64_t solve(int64_t x, int64_t y) {
	if (x <= 1 || y <= 1) {
		return x > 1 || y > 1;
	}
	return 2;
}

int main() {
	int64_t t, x, y;
	string s;
	cin >> t;
	for (int q = 0; q < t; ++q) {
		cin >> x >> y;
		int64_t ans = solve(x, y);
		cout << ans << endl;
	}
	return 0;
}
