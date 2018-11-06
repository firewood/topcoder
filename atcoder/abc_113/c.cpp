// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> II;

int main(int argc, char *argv[]) {
	int n, m, y;
	cin >> n >> m;
	vector<int> p(m), s(m);
	vector<vector<II>> v(n + 1);
	for (int i = 0; i < m; ++i) {
		cin >> p[i] >> y;
		v[p[i]].push_back(II(y, i));
	}
	for (int i = 1; i <= n; ++i) {
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < (int)v[i].size(); ++j) {
			s[v[i][j].second] = j + 1;
		}
	}
	for (int i = 0; i < m; ++i) {
		printf("%06d%06d\n", p[i], s[i]);
	}
	return 0;
}
