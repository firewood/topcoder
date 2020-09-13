#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <algorithm>
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

const int MX = 1500;

struct Point {
	double x;
	double y;
	double dist(const Point& p) {
		double dx = x - p.x, dy = y - p.y;
		return sqrt(dx * dx + dy * dy);
	}
};

struct Circle {
	Point p;
	double r;
	bool is_cross(const Circle& c) {
		return p.dist(c.p) < r + c.r;
	}
};

void solve() {
	vector<Circle> ans;
	int x = 100, y = 100, dir = 1;
	for (int r = 100; r >= 1; --r) {
		Circle c;
		c.p.x = x;
		c.p.y = y;
		c.r = r;
		for (auto x : ans) {
			while (x.is_cross(c)) {
				c.p.y = ++y;
			}
		}
		ans.emplace_back(c);
		int nx = x + dir * (r + r - 1);
		if (nx + r - 1 > MX) {
			dir = -1;
			x = MX - r - 1;
		} else if (nx - (r - 1) < 0) {
			dir = 1;
			x = r - 1;
		} else {
			x = nx;
		}
	}
	reverse(ans.begin(), ans.end());
	for (auto c : ans) {
		cout << c.p.x << " " << c.p.y << endl;
	}
}

int main() {
	solve();
	return 0;
}
