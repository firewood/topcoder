// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	int n, d;
	cin >> n >> d;
	vector<vector<int>> x(n);
	for (int i = 0; i < n; ++i) {
		x[i].resize(d);
		for (int j = 0; j < d; ++j) {
			cin >> x[i][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			int sum = 0;
			for (int k = 0; k < d; ++k) {
				sum += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
			}
			int r = (int)sqrt(sum + 1e-8);
			ans += (sum == r * r);
		}
	}
	cout << ans << endl;
	return 0;
}
