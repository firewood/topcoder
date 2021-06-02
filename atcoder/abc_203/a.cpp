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

int64_t solve(int64_t a, int64_t b, int64_t c) {
	int64_t ans = 0;
	if (a == b) ans = c;
	if (b == c) ans = a;
	if (c == a) ans = b;
	return ans;
}

int main() {
	int64_t a, b, c;
	std::cin >> a >> b >> c;
	cout << solve(a, b, c) << endl;
	return 0;
}
