// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int INF = 1 << 30;

int solve(vector<int> x, vector<int> y, vector<string> dir) {
	int ans = INF;
	int n = (int)x.size();
	map<int, set<int>> a, b, v, h;
	for (int i = 0; i < n; ++i) {
		if (dir[i] == "L") {
			a[x[i] - y[i]].insert(x[i]);
			h[y[i]].insert(x[i]);
		}
		if (dir[i] == "R") {
			b[x[i] + y[i]].insert(x[i]);
		}
		if (dir[i] == "D") {
			v[x[i]].insert(y[i]);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (dir[i] == "R") {
			if (h.find(y[i]) != h.end()) {
				set<int>& s = h[y[i]];
				auto it = s.lower_bound(x[i]);
				if (it != s.end()) {
					ans = min(ans, (*it - x[i]) * 5);
				}
			}
		}
		if (dir[i] != "U") {
			continue;
		}
		int key = x[i] - y[i];
		if (a.find(key) != a.end()) {
			set<int>& s = a[key];
			auto it = s.lower_bound(x[i]);
			if (it != s.end()) {
				ans = min(ans, (*it - x[i]) * 10);
			}
		}
		key = x[i] + y[i];
		if (b.find(key) != b.end()) {
			set<int>& s = b[key];
			auto it = s.lower_bound(x[i]);
			if (it != s.begin()) {
				--it;
				ans = min(ans, (x[i] - *it) * 10);
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
	return ans;
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
		ans = solve(x, y, dir);
		map<string, string> t;
		t["D"] = "U";
		t["U"] = "D";
		t["L"] = "R";
		t["R"] = "L";
		for (int i = 0; i < n; ++i) {
			x[i] = -x[i];
			y[i] = -y[i];
			dir[i] = t[dir[i]];
		}
		ans = min(ans, solve(x, y, dir));
		if (ans == INF) {
			cout << "SAFE" << endl;
		} else {
			cout << ans << endl;
		}
	}
	return 0;
}
