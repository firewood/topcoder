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

int64_t f(int64_t a, int64_t b) {
	return (a + b) * (a * a + b * b);
}

int64_t solve(int64_t N) {
	int64_t ans = 1LL << 62;
	for (int64_t a = 1000000, b = 0; a >= 0; --a) {
		while (f(a, b) < N) {
			++b;
		}
		ans = min(ans, f(a, b));
	}
	return ans;
}

int main() {
	int64_t N;
	std::cin >> N;
	cout << solve(N) << endl;
	return 0;
}
