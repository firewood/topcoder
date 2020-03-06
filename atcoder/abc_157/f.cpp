// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

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
	double c;
	double r;
	vector<Point> cross(const Circle& c) {
		vector<Point> pp;
		double dist = p.dist(c.p);
		if (dist <= r + c.r && r <= dist + c.r && r + dist >= c.r) {
			double dx = c.p.x - p.x, dy = c.p.y - p.y, dd = dx * dx + dy * dy;
			double a = (dd + r * r - c.r * c.r) / 2;
			pp.push_back({
				(a * dx + dy * sqrt(dd * r * r - a * a)) / dd + p.x,
				(a * dy - dx * sqrt(dd * r * r - a * a)) / dd + p.y
			});
			pp.push_back({
				(a * dx - dy * sqrt(dd * r * r - a * a)) / dd + p.x,
				(a * dy + dx * sqrt(dd * r * r - a * a)) / dd + p.y
			});
		}
		return pp;
	}
};

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1, k;
		cin >> n >> k;
		if (n < 0) return 0;
		vector<Circle> cc(n);
		for (int i = 0; i < n; ++i) {
			cin >> cc[i].p.x >> cc[i].p.y >> cc[i].c;
		}
		double left = 0, right = 1e9;
		for (int t = 0; t < 100; ++t) {
			double mid = (left + right) / 2;
			for (int i = 0; i < n; ++i) {
				cc[i].r = mid / cc[i].c;
			}
			vector<Point> pp;
			for (int i = 0; i < n; ++i) {
				pp.push_back(cc[i].p);
				for (int j = i + 1; j < n; ++j) {
					for (auto p : cc[i].cross(cc[j])) {
						pp.push_back(p);
					}
				}
			}
			int mc = 0;
			for (auto p : pp) {
				int cnt = 0;
				for (auto c : cc) {
					cnt += p.dist(c.p) <= c.r + 1e-12;
				}
				mc = max(mc, cnt);
			}
			if (mc >= k) {
				right = mid;
			} else {
				left = mid;
			}
		}
		cout << right << endl;
	}
	return 0;
}
