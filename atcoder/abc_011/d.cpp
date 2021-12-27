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
typedef pair<int, int> II;

map<II, LD> memo;

LD combination(int n, int r) {
	if (r > n) return 0;
	r = min(r, n - r);
	II key(n, r);
	if (memo.find(key) == memo.end()) {
		LD x = 1;
		for (int i = 0; i < r; ++i) {
			x *= n - i;
			x /= i + 1;
		}
		memo[key] = x;
	}
	return memo[key];
}

LD solve(int N, int64_t D, int64_t X, int64_t Y) {
	LD ans = 0;
	if ((X % D) != 0 || (Y % D) != 0) {
		return 0;
	}
	int64_t xs = abs(X) / D, ys = abs(Y) / D;
	if ((N - xs - ys) % 2) {
		return 0;
	}
	LD b = 1;
	for (int i = 0; i < N; ++i) {
		b *= 4;
	}
	for (int xp = 0; xs + xp <= N; xp += 2) {
		int yp = N - xs - xp - ys;
		if (yp < 0) {
			break;
		}
		int r1 = N;
		int c1 = xs + xp / 2;
		int r2 = r1 - c1;
		int c2 = xp / 2;
		int r3 = r2 - c2;
		int c3 = ys + yp / 2;
		LD x = combination(r3, c3);
		x *= combination(r2, c2);
		x /= b;
		x *= combination(r1, c1);
		ans += x;
	}
	return ans;
}

int main() {
	cout.precision(20);
	int N;
	int64_t D, X, Y;
	std::cin >> N >> D >> X >> Y;
	cout << solve(N, D, X, Y) << endl;
	return 0;
}
