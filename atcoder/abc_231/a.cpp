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

LD solve(int64_t D) {
	return LD(D) / 100;
}

int main() {
	cout.precision(20);
	int64_t D;
	std::cin >> D;
	cout << solve(D) << endl;
	return 0;
}
