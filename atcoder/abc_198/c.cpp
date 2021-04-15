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
typedef long double LD;
LD EPS = 1e-14;

LL solve(LD R, LD X, LD Y) {
	LD count = sqrt(X * X + Y * Y) / R;
	if (count < 1.0 - EPS) {
		return 2;
	} else {
		return ceil(count);
	}
}

int main() {
	long long R, X, Y;
	std::cin >> R >> X >> Y;
	cout << solve(R, X, Y) << endl;
	return 0;
}
