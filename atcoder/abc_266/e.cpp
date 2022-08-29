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

LD solve(int64_t N) {
	LD expected = 3.5;
	for (int i = 1; i < N; ++i) {
		LD next = 0;
		for (int j = 1; j <= 6; ++j) {
			next += max(LD(j), expected);
		}
		expected = next / 6;
	}
	return expected;
}

int main() {
	cout.precision(20);
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
