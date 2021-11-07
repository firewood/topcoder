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

int64_t solve(long double X) {
	int64_t ans = round(X + 1e-10);
	return ans;
}

int main() {
	long double X;
	std::cin >> X;
	cout << solve(X) << endl;
	return 0;
}
