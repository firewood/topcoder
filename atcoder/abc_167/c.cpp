// C.

#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, m, x;
	cin >> n >> m >> x;
	int ans = 1 << 30;
	vector<int> c(n);
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	for (int t = 1; t < (1 << n); ++t) {
		int cost = 0;
		vector<int> u(m);
		for (int i = 0; i < n; ++i) {
			if (t & (1 << i)) {
				cost += c[i];
				for (int j = 0; j < m; ++j) {
					u[j] += a[i][j];
				}
			}
		}
		bool ok = true;
		for (int j = 0; j < m; ++j) {
			if (u[j] < x) {
				ok = false;
				break;
			}
		}
		if (ok) {
			ans = min(ans, cost);
		}
	}
	cout << (ans < (1 << 30) ? ans : -1) << endl;
	return 0;
}
