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

int64_t solve(int64_t X, int64_t Y, int64_t Z) {
	int64_t ans = -1;
	if (Y < 0) {
		X = -X;
		Y = -Y;
		Z = -Z;
	}
	if (X <= Y) {
		ans = abs(X);
	} else if (Z <= Y) {
		ans = abs(Z) + X - Z;
	}
	return ans;
}

int main() {
	int64_t X, Y, Z;
	std::cin >> X >> Y >> Z;
	cout << solve(X, Y, Z) << endl;
	return 0;
}
