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

typedef long long LL;

LL solve(long long R, long long B, long long x, long long y) {
	LL left = 0, right = min(R, B) + 1;		// left: possible, right: impossible
	auto possible = [&](LL t) -> bool {
		LL rr = R - t, rb = B - t;
		return rr >= 0 && rb >= 0 && (rr / (x - 1) + rb / (y - 1)) >= t;
	};
	while (right - left > 1) {
		LL mid = (left + right) / 2;
		if (possible(mid)) {
			left = mid;
		} else {
			right = mid;
		}
	}
	return left;
}

int main() {
    long long R, B, x, y;
	std::cin >> R >> B >> x >> y;
	cout << solve(R, B, x, y) << endl;
	return 0;
}
