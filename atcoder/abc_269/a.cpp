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

int64_t solve(int64_t a, int64_t b, int64_t c, int64_t d) {
	return (a + b) * (c - d);
}

int main() {
	int64_t a, b, c, d;
	std::cin >> a >> b >> c >> d;
	cout << solve(a, b, c, d) << endl;
	cout << "Takahashi" << endl;
	return 0;
}
