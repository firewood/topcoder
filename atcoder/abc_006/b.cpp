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
#include <atcoder/modint>

using namespace std;

int solve(int n) {
	int a = 0, b = 0, c = 1;
	for (int i = 1; i < n; ++i) {
		int d = (a + b + c) % 10007;
		a = b;
		b = c;
		c = d;
	}
	return a;
}

int main() {
	int64_t n;
	std::cin >> n;
	cout << solve(n) << endl;
	return 0;
}
