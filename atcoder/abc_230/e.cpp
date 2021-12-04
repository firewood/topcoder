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

int64_t solve(int64_t N) {
	int64_t ans = 0, lo, hi;
	for (int64_t i = 1; i * i <= N; ++i) {
		lo = N / (i + 1) + 1;
		hi = N / i;
		ans += (hi - lo + 1) * i;
	}
	for (int64_t i = 1; i < lo; ++i) {
		ans += N / i;
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
