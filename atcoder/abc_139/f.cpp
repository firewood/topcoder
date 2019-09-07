// F.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long double LD;

int main(int argc, char* argv[]) {
	cout.precision(12);
	while (true) {
		int n = -1;
		cin >> n;
		if (n <= 0) break;
		vector<LD> x(n), y(n);
		vector<pair<LD, int>> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> x[i] >> y[i];
			v[i] = {atan2(y[i], x[i]), i};
		}
		sort(v.begin(), v.end());
		LD ans = 0;
		for (int i = 0; i < n; ++i) {
			LD xs = 0, ys = 0;
			for (int j = 0; j < n; ++j) {
				int k = v[(i + j) % n].second;
				xs += x[k], ys += y[k];
				ans = max(ans, sqrt(xs * xs + ys * ys));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
