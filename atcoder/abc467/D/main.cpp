#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
const string YES = "Yes";
const string NO = "No";

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }
int64_t lcm(int64_t a, int64_t b) { return (a / gcd(a, b)) * b; }

tuple<int64_t, int64_t, int64_t> get_param(int64_t Px, int64_t Py, int64_t Qx, int64_t Qy) {
	int64_t a = 2 * (Qx - Px), b = 2 * (Qy - Py), c = Px * Px + Py * Py - Qx * Qx - Qy * Qy;
	int64_t g = gcd(a, gcd(b, c));
	a /= g;
	b /= g;
	c /= g;
	if (a < 0 || (a == 0 && b < 0)) {
		a = -a;
		b = -b;
		c = -c;
	}
	return { a, b, c };
}

bool solve(int64_t P_x, int64_t P_y, int64_t Q_x, int64_t Q_y, int64_t R_x, int64_t R_y, int64_t S_x, int64_t S_y) {
	// (Px - x) ^ 2 + (Py - y) ^ 2 = (Qx - x) ^ 2 + (Qy - y) ^ 2
	// 2 * (Qx - Px) * x + 2 * (Qy - Py) * y + Px * Px + Py * Py - Qx * Qx - Qy * Qy = 0
	auto [a1, b1, c1] = get_param(P_x, P_y, Q_x, Q_y);
	auto [a2, b2, c2] = get_param(R_x, R_y, S_x, S_y);
	return (a1 == a2 && b1 == b2 && c1 == c2) || (a1 * b2 != a2 * b1);
}

void process_case() {
	int64_t P_x, P_y, Q_x, Q_y, R_x, R_y, S_x, S_y;
	cin >> P_x >> P_y >> Q_x >> Q_y >> R_x >> R_y >> S_x >> S_y;
	auto ans = solve(P_x, P_y, Q_x, Q_y, R_x, R_y, S_x, S_y);
	cout << (ans ? YES : NO) << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		process_case();
	}
}
