#include <algorithm>
#include <cctype>
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

int solve(int n, int m, std::vector<int> x, std::vector<int> y, std::vector<int> a) {
	int ans = 0, vi = 0;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i) {
		v.push_back({ x[i], y[i] });
	}
	sort(v.begin(), v.end());
	sort(a.begin(), a.end());
	priority_queue<int, vector<int>, greater<>> q;
	for (int i = 0; i < m; ++i) {
		while (vi < n && v[vi].first <= a[i]) {
			q.emplace(v[vi++].second);
		}
		while (!q.empty()) {
			int top = q.top();
			q.pop();
			if (top >= a[i]) {
				++ans;
				break;
			}
		}
	}
	return ans;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		std::cin >> x[i] >> y[i];
	}
	std::vector<int> a(m);
	for (int i = 0; i < m; i++) {
		std::cin >> a[i];
	}
	cout << solve(n, m, x, y, a) << endl;
	return 0;
}
