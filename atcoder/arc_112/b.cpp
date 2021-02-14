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

LL solve(long long B, long long C) {
	LL ans = 0, C1 = max(0LL, C - 1), C2 = max(0LL, C - 2);
	if (B <= 0) {
		LL left = B - C / 2;
		LL right = min(-1LL, B + C2 / 2);
		ans = right - left + 1;
		left = max(0LL, -B - C1 / 2);
		right = -(B - C1 / 2);
		ans += right - left + 1;
	} else {
		LL left = max(0LL, B - C / 2);
		LL right = B + C2 / 2;
		ans = right - left + 1;
		left = -B - C1 / 2;
		right = min(-1LL, -(B - C1 / 2));
		ans += right - left + 1;
	}
	return ans;
}

int main() {
    long long B, C;
	std::cin >> B >> C;
	cout << solve(B, C) << endl;
	return 0;
}
