#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

typedef long double LD;
const LD EPS = 1e-10;

struct Point {
	long double x;
	long double y;
	bool operator < (const Point& p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
	bool operator == (const Point& p) const {
		return x == p.x && y == p.y;
	}
	long double distance(const Point& p) const {
		long double dx = x - p.x, dy = y - p.y;
		return sqrt(dx * dx + dy * dy);
	}
};

long double cross(const Point& O, const Point& A, const Point& B) {
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// 凸包
vector<Point> convex_hull(vector<Point>& P)
{
	int n = (int)P.size(), k = 0;
	if (n <= 2) {
		return P;
	}
	vector<Point> H(2 * n);
	sort(P.begin(), P.end());
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	for (int i = n - 2, t = k + 1; i >= 0; i--) {
		while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	return vector<Point>(H.begin(), H.begin() + k - 1);
}

// 外接円
void circumscribed_circle(const Point& a, const Point& b, const Point& c, Point& cc, LD& r)
{
	LD a2 = a.x * a.x + a.y * a.y, b2 = b.x * b.x + b.y * b.y, c2 = c.x * c.x + c.y * c.y;
	LD x21 = b.x - a.x, x31 = c.x - a.x, y12 = a.y - b.y, y13 = a.y - c.y;
	cc.y = 0.5 * (x31 * (a2 - b2) - x21 * (a2 - c2)) / (x31 * y12 - x21 * y13);
	if (fabs(x21) <= EPS) {
		cc.x = (y13 * cc.y - 0.5 * (a2 - c2)) / x31;
	} else {
		cc.x = (y12 * cc.y - 0.5 * (a2 - b2)) / x21;
	}
	r = sqrt((a.x - cc.x) * (a.x - cc.x) + (a.y - cc.y) * (a.y - cc.y));
}

int main(int argc, char* argv[]) {
	cout.precision(20);

	for (int t = 0; t < 10000000; ++t) {
		Point p[3];
		for (int i = 0; i < 3; ++i) {
			bool same = true;
			while (same) {
				p[i].x = (rand() % 256) - 128;
				p[i].y = (rand() % 256) - 128;
				same = false;
				for (int j = 0; j < i; ++j) {
					if (p[i] == p[j]) {
						same = true;
					}
				}
			}
		}

		Point cc;
		LD r;
		circumscribed_circle(p[0], p[1], p[2], cc, r);
		for (int i = 0; i < 3; ++i) {
			if (!isnormal(r) || r <= 0 || fabs(cc.distance(p[i]) - r) > EPS) {
				sort(p, p + 3);
				LD d1, d2;
				if (p[1].x - p[0].x > EPS) {
					d1 = (p[1].y - p[0].y) / (p[1].x - p[0].x);
					d2 = (p[2].y - p[0].y) / (p[2].x - p[0].x);
				} else {
					d1 = (p[1].x - p[0].x) / (p[1].y - p[0].y);
					d2 = (p[2].x - p[0].x) / (p[2].y - p[0].y);
				}
				if (d1 != d2) {
					cout << "FAILED:";
					for (int i = 0; i < 3; ++i) {
						cout << " " << cc.distance(p[i]);
					}
					cout << endl;
					break;
				}
			}
		}
	}

	return 0;
}
