// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int INF = 1 << 30;

int solve(int n, vector<int> x, vector<int> y, vector<string> dir) {
	int ans = INF;
	map<int, set<int>> d, v;
	for (int i = 0; i < n; ++i) {
		if (dir[i] == "R") {
			d[x[i] + y[i]].insert(y[i]);
		}
		if (dir[i] == "D") {
			v[x[i]].insert(y[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (dir[i] == "U") {
			int key = x[i] + y[i];
			if (d.find(key) != d.end()) {
				set<int>& s = d[key];
				auto it = s.lower_bound(y[i]);
				if (it != s.end()) {
					ans = min(ans, (*it - y[i]) * 10);
				}
			}
			if (v.find(x[i]) != v.end()) {
				set<int>& s = v[x[i]];
				auto it = s.lower_bound(y[i]);
				if (it != s.end()) {
					ans = min(ans, (*it - y[i]) * 5);
				}
			}
		}
	}
	return ans;
}

void rotate(int n, vector<int> &x, vector<int> &y, vector<string> &dir) {
	map<string, string> t;
	t["D"] = "R", t["U"] = "L", t["L"] = "D", t["R"] = "U";
	for (int i = 0; i < n; ++i) {
		int nx = -y[i];
		y[i] = x[i], x[i] = nx;
		dir[i] = t[dir[i]];
	}
}

int main(int argc, char* argv[]) {
	cout.precision(20);
#ifdef _MSC_VER
	while (true)
#endif
	{
		int ans = INF;
		int n = -1;
		cin >> n;
		if (n < 0) return 0;
		vector<int> x(n), y(n);
		vector<string> dir(n);
		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i] >> dir[i];
		}
		for (int i = 0; i < 4; ++i) {
			ans = min(ans, solve(n, x, y, dir));
			rotate(n, x, y, dir);
		}
		if (ans == INF) {
			cout << "SAFE" << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}
