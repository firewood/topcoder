// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	map<int, int> m[2];
	for (int i = 0; i < n; ++i) {
		int v;
		cin >> v;
		m[i % 2][v] += 1;
	}
	vector<II> a[2];
	for (int i = 0; i < 2; ++i) {
		for (const auto kv : m[i]) {
			a[i].push_back(II(kv.second, kv.first));
		}
	}
	sort(a[0].rbegin(), a[0].rend());
	sort(a[1].rbegin(), a[1].rend());
	int ans = 1 << 30;
	for (int i = 0; i < min(4, (int)a[0].size()); ++i) {
		for (int j = 0; j < min(4, (int)a[1].size()); ++j) {
			int p = n - a[0][i].first;
			int q = n - a[1][j].first;
			if (a[0][i].second != a[1][j].second) {
				p -= a[1][j].first;
				q -= a[0][i].first;
			}
			ans = min({ ans, p, q });
		}
	}
	cout << ans << endl;
	return 0;
}
