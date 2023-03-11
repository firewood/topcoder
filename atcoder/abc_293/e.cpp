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

int64_t solve(int64_t A, int64_t X, int64_t M) {
	if (M <= 1) {
		return 0;
	}
	int64_t ans = 0, loops = 10000000, a = 1, i;
	for (i = 0; i < min(X, loops); ++i) {
		ans = (ans + a) % M;
		a = (a * A) % M;
	}
	int64_t sum = ans, base = a;
	for (; i < X - loops; i += loops) {
		ans = (ans + sum * a) % M;
		a = (a * base) % M;
	}
	for (; i < X; ++i) {
		ans = (ans + a) % M;
		a = (a * A) % M;
	}
	return ans % M;
}

int main() {
	int64_t A, X, M;
	std::cin >> A >> X >> M;
	cout << solve(A, X, M) << endl;
	return 0;
}
