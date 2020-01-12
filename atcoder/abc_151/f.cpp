// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

typedef long double LD;
const LD EPS = 1e-8;

struct Point {
	long double x;
	long double y;
	int i;
	bool operator < (const Point& p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

long double cross(const Point& O, const Point& A, const Point& B) {
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

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

void circumscribed_circle(LD x1, LD y1, LD x2, LD y2, LD x3, LD y3, LD& cx, LD& cy, LD& r)
{
	LD x21 = x2 - x1, x31 = x3 - x1, y12 = y1 - y2, y13 = y1 - y3;
	cy = (x31 * (x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2) - x21 * (x1 * x1 + y1 * y1 - x3 * x3 - y3 * y3))
	     / (2 * x31 * y12 - 2 * x21 * y13);
	if (fabs(x21) <= EPS) {
		cx = (2 * y13 * cy - x1 * x1 - y1 * y1 + x3 * x3 + y3 * y3) / (2 * x31);
	} else {
		cx = (2 * y12 * cy - x1 * x1 - y1 * y1 + x2 * x2 + y2 * y2) / (2 * x21);
	}
	r = sqrt((x1 - cx) * (x1 - cx) + (y1 - cy) * (y1 - cy));
}

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int n = -1;
		cin >> n;
		if (n <= 0) return 0;
		vector<Point> xy(n);
		for (int i = 0; i < n; ++i) {
			cin >> xy[i].x >> xy[i].y;
			xy[i].i = i;
		}
		LD ans = 1e10;
		vector<Point> ch = convex_hull(xy);
		int sz = ch.size();
		for (int i = 0; i < sz; ++i) {
			for (int j = i + 1; j < sz; ++j) {
				LD cx = (ch[i].x + ch[j].x) * 0.5, cy = (ch[i].y + ch[j].y) * 0.5;
				LD dx = ch[i].x - ch[j].x, dy = ch[i].y - ch[j].y;
				LD r = sqrt(dx * dx + dy * dy) * 0.5;
				auto ok = [&] {
					for (int l = 0; l < sz; ++l) {
						LD dx = ch[l].x - cx;
						LD dy = ch[l].y - cy;
						if (sqrt(dx * dx + dy * dy) > r + EPS) {
							return false;
						}
					}
					return true;
				};
				if (ok()) {
					ans = min(ans, r);
				}
				for (int k = j + 1; k < sz; ++k) {
					circumscribed_circle(ch[i].x, ch[i].y, ch[j].x, ch[j].y, ch[k].x, ch[k].y, cx, cy, r);
					if (ok()) {
						ans = min(ans, r);
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
