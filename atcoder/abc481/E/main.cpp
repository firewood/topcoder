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

int64_t gcd(int64_t a, int64_t b) { return b ? gcd(b, a % b) : a; }
int64_t lcm(int64_t a, int64_t b) { return (a / gcd(a, b)) * b; }

struct Point {
	int64_t x;
	int64_t y;
	bool is_first_half() const {
		return y > 0 || (y == 0 && x > 0);
	}
	int64_t cross_product(const Point &p) const {
		return x * p.y - p.x * y;
	}
	bool operator < (const Point &p) const {
		int h1 = is_first_half(), h2 = p.is_first_half();
		if (h1 != h2) {
			return h1 > h2;
		}
		return cross_product(p) > 0;
	}
	void normalize() {
		int64_t xs = x > 0 ? 1 : -1, ys = y > 0 ? 1 : -1;
		if (x == 0) {
			y = ys;
		} else if (y == 0) {
			x = xs;
		} else {
			int64_t g = gcd(x * xs, y * ys);
			x /= g;
			y /= g;
		}
	}
};

int64_t solve(int64_t N, vector<int64_t> X, vector<int64_t> Y) {
	int64_t ans = 0;

	vector<Point> p(N);
	for (int i = 0; i < N; ++i) {
		p[i].x = X[i];
		p[i].y = Y[i];
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < N; ++i) {
		p.emplace_back(p[i]);
	}

	int64_t right = 0;
	for (int64_t i = 0; i < N; ++i) {
		right = max(right, i + 1);
		while (right < i + N && p[i].cross_product(p[right]) > 0) {
			++right;
		}
		ans = max(ans, right - i);
	}

	return ans;
}

void process_case() {
	int64_t N;
	cin >> N;
	vector<int64_t> X(N), Y(N);
	for (int64_t i = 0; i < N; ++i) {
		cin >> X[i] >> Y[i];
	}
	auto ans = solve(N, X, Y);
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		process_case();
	}
}
