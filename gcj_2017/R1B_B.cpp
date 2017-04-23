// Google Code Jam 2017 Round 1B
// Problem B. Stable Neigh-bors

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> II;
typedef vector<II> IIVec;

string solve() {
	int r, ry, y, yb, b, rb, n;
	cin >> n >> r >> ry >> y >> yb >> b >> rb;
	string bb;
	if (ry) {
		for (int i = 0; i < ry; ++i) {
			bb += "BO";
		}
		if (b == ry && (n == b + ry)) {
			return bb;
		}
		bb += "B";
		b -= ry;
		if (b < 1) {
			return "IMPOSSIBLE";
		}
	}
	string rr;
	if (yb) {
		for (int i = 0; i < yb; ++i) {
			rr += "RG";
		}
		if (r == yb && (n == r + yb)) {
			return rr;
		}
		rr += "R";
		r -= yb;
		if (r < 1) {
			return "IMPOSSIBLE";
		}
	}
	string yy;
	if (rb) {
		for (int i = 0; i < rb; ++i) {
			yy += "YV";
		}
		if (y == rb && (n == y + rb)) {
			return yy;
		}
		yy += "Y";
		y -= rb;
		if (y < 1) {
			return "IMPOSSIBLE";
		}
	}
	n = b + r + y;
	if (r > n / 2 || y > n / 2 || b > n / 2) {
		return "IMPOSSIBLE";
	}
	IIVec x;
	x.push_back(II(r, 'R'));
	x.push_back(II(y, 'Y'));
	x.push_back(II(b, 'B'));
	sort(x.rbegin(), x.rend());
	char w[1024] = {};
	for (int i = 0; i < 2; ++i) {
		int m = (n / 2) + (i == 0 && (n % 2) != 0);
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < 3; ++k) {
				if (x[k].first) {
					--x[k].first;
					w[i + j * 2] = x[k].second;
					break;
				}
			}
		}
	}
	string ans = w;
	if (!bb.empty()) {
		int pos = ans.find('B');
		ans.replace(pos, 1, bb);
	}
	if (!rr.empty()) {
		int pos = ans.find('R');
		ans.replace(pos, 1, rr);
	}
	if (!yy.empty()) {
		int pos = ans.find('Y');
		ans.replace(pos, 1, yy);
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		string ans = solve();
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
