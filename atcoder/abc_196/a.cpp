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

static const LL INF = 1LL << 60;

LL solve(long long a, long long b, long long c, long long d) {
	LL ans = -INF;
	for (LL x = a; x <= b; ++x) {
		for (LL y = c; y <= d; ++y) {
			ans = max(ans, x - y);
		}
	}
	return ans;
}

int main() {
	long long a, b, c, d;
	std::cin >> a >> b >> c >> d;
	cout << solve(a, b, c, d) << endl;
	return 0;
}
