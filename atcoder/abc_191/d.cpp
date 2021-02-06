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

const LD EPS = 1e-15;

LL solve(long double X, long double Y, long double R) {
	LL ans = 0;
	for (LL y = Y - R - 1; y <= Y + R + 1; ++y) {
		LD w = sqrt(max((LD)0.0, R * R - (y - Y) * (y - Y)));
		LL left = X - w - 1, right = X + w + 1;
		for (int i = 0; i < 2; ++i) {
			if (((left - X) * (left - X) + (Y - y) * (Y - y)) > R * R + EPS) {
				++left;
			}
			if (((right - X) * (right - X) + (Y - y) * (Y - y)) > R * R + EPS) {
				--right;
			}
		}
		ans += max(0LL, right - left + 1);
	}
	return ans;
}

int main() {
	cout.precision(20);
    long double X, Y, R;
	std::cin >> X >> Y >> R;
	cout << solve(X, Y, R) << endl;
	return 0;
}
