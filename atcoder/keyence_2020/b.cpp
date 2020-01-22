// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[]) {
	int n, ans = 0, prev = -2e9;
	cin >> n;
	vector<II> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	v.push_back({ 2e9 + 2, 0 });
	sort(v.begin(), v.end());
	bool ni = false;
	for (int i = 0; i < n; ++i) {
		int cl = v[i].first - v[i].second;
		int cr = v[i].first + v[i].second;
		if (cr <= prev) {
			prev = cr;
		} else if (cl >= prev) {
			++ans;
			prev = cr;
		}
	}
	cout << ans << endl;
	return 0;
}
