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

LL x;
map<LL, LL> memo;

LL calc(LL y) {
	LL diff = abs(x - y), r;
	if (y <= 1) {
		return diff;
	}
	if (memo.find(y) != memo.end()) {
		return memo[y];
	}
	if (y % 2) {
		r = 2 + min(calc(y / 2), calc(y / 2 + 1));
	} else {
		r = 1 + calc(y / 2);
	}
	return memo[y] = min(diff, r);
}

LL solve(long long X, long long Y) {
	if (X >= Y) {
		return X - Y;
	} else {
		x = X;
		memo.clear();
		return calc(Y);
	}
}

int main() {
    long long X;
	std::cin >> X;
	long long Y;
	std::cin >> Y;
	cout << solve(X, Y) << endl;
	return 0;
}
