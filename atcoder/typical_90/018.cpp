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

typedef long double LD;

LD solve(int64_t T, int64_t L, int64_t X, int64_t Y, int64_t E) {
    LD r = M_PI * 2.0 * (LD(-E) / T - 0.25), y = 0.5 * L * cos(r), z = 0.5 * L * (sin(r) + 1.0);
    LD d = sqrt((y - Y) * (y - Y) + X * X), h = sqrt(z * z);
    LD a = atan2(h, d);
    return 360 * a / (M_PI * 2.0);
}

int main() {
    cout.precision(20);
    int64_t T, L, X, Y, Q, E;
	std::cin >> T >> L >> X >> Y >> Q;
	for (int i = 0; i < Q; i++) {
        std::cin >> E;
        cout << solve(T, L, X, Y, E) << endl;
	}
	return 0;
}
