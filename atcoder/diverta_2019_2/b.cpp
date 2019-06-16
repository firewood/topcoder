// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> II;

int main(int argc, char *argv[]) {
	map<II, vector<int>> m;
	int n;
	cin >> n;
	vector<II> xy(n);
	map<II, int> xyi;
	for (int i = 0; i < n; ++i) {
		cin >> xy[i].first >> xy[i].second;
		xyi[xy[i]] = i;
	}
	int ans = n;
	sort(xy.begin(), xy.end());
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int cost = n;
			for (int k = 0; k < n; ++k) {
				II temp(xy[k].first - xy[j].first + xy[i].first, xy[k].second - xy[j].second + xy[i].second);
				auto x = xyi.find(temp);
				if (x != xyi.end()) {
					--cost;
				}
			}
			ans = min(ans, cost);
		}
	}
	cout << ans << endl;
	return 0;
}
