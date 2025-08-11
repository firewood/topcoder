#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <numeric>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

typedef long double LD;
typedef pair<int, int> II;
typedef pair<int64_t, II> III;

static const int64_t INF = 1LL << 60;

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }
int64_t lcm(int64_t a, int64_t b) { return (a / gcd(a, b)) * b; }

inline void norm_dxdy1(int& dx, int& dy) {
	if (dx == 0) {
		dy = abs(dy);
	} else if (dy == 0) {
		dx = abs(dx);
	} else if (dy < 0) {
		dx = -dx;
		dy = -dy;
	}
}

inline void norm_dxdy2(int& dx, int& dy) {
	if (dx == 0) {
		dy = 1;
	} else if (dy == 0) {
		dx = 1;
	} else {
		int g = gcd(abs(dx), dy);
		dx /= g;
		dy /= g;
	}
}

int64_t count(vector<II>& v) {
	int64_t sum = 0;
	sort(v.begin(), v.end());
	int vi = 0;
	while (vi < v.size()) {
		II key = v[vi];
		int64_t cnt = 0;
		while (v[vi] == key) {
			++cnt;
			++vi;
		}
		sum += cnt * (cnt - 1) / 2;
	}
	return sum;
}

int64_t solve(int64_t N, std::vector<int> X, std::vector<int> Y) {
	int64_t ans = 0, dc = 0;

	vector<II> v1, v2;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			int dx = X[i] - X[j], dy = Y[i] - Y[j];
			norm_dxdy1(dx, dy);
			v1.emplace_back(II(dx, dy));
			norm_dxdy2(dx, dy);
			v2.emplace_back(II(dx, dy));
		}
	}
	return count(v2) - count(v1) / 2;
}

int main() {
	int64_t N;
	std::cin >> N;
	std::vector<int> X(N), Y(N);
	for (int i = 0; i < N; i++) {
		std::cin >> X[i] >> Y[i];
	}
	cout << solve(N, X, Y) << endl;
	return 0;
}
