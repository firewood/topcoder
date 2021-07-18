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

bool possible(int64_t N, int64_t d) {
	while (N > 0) {
		int64_t last = N % 10;
		if (last < d && N >= 10 && (10 + last) <= 3 * d) {
			last += 10;
			N -= 10;
		}
		if (last > 3 * d) {
			return false;
		}
		d = min(d, last);
		N /= 10;
	}
	return true;
}

int64_t solve(int64_t N) {
	for (int64_t n = 1; n <= 6; ++n) {
		if (possible(N, n)) {
			return n;
		}
	}
	return -1;
}

int main() {
	int64_t T, N;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		cout << solve(N) << endl;
	}
	return 0;
}
