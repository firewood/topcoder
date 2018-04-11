// B.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	cout.precision(10);
	int sx, sy, n;
	cin >> sx >> sy >> n;
	vector<pair<int, int> > v;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	double ans = 1e+10;
	for (int i = 0; i < n; ++i) {
		int ax = v[i].first, bx = v[(i + 1) % n].first;
		int ay = v[i].second, by = v[(i + 1) % n].second;
		double dx = bx - ax, dy = by - ay;
		double px = sx - ax, py = sy - ay;
		double cp = fabs(dx * py - dy * px);
		double l = sqrt(dx * dx + dy * dy);
		ans = min(ans, cp / l);
	}
	cout << ans << endl;
	return 0;
}
