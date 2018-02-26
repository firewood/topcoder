// B.

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
	long double x;
	long double y;
	int i;
	bool operator < (const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

long double cross(const Point &O, const Point &A, const Point &B) {
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> &P)
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

long double rad(const Point &a, const Point &b, const Point &c) {
	long double a1 = a.x - b.x, a2 = a.y - b.y;
	long double b1 = c.x - b.x, b2 = c.y - b.y;
	long double cos = (a1 * b1 + a2 * b2) / (sqrt(a1 * a1 + a2 * a2) * sqrt(b1 * b1 + b2 * b2));
	return acos(cos);
}

int main(int argc, char *argv[])
{
	cout.precision(10);
	int n;
	cin >> n;
	vector<Point> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i].x;
		cin >> p[i].y;
		p[i].i = i;
	}
	vector<long double> res(n);
	vector<Point> ch = convex_hull(p);
	if (ch.size() <= 2) {
		for (int i = 0; i != ch.size(); ++i) {
			res[ch[i].i] = 1.0 / ch.size();
		}
	} else {
		for (int i = 0; i != ch.size(); ++i) {
			int prev = (i - 1 + ch.size()) % ch.size();
			int next = (i + 1) % ch.size();
			long double r = rad(ch[prev], ch[i], ch[next]);
			res[ch[i].i] = (M_PI - r) / (2 * M_PI);
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << res[i] << endl;
	}
	return 0;
}
