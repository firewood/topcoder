// J.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, m, a;
	cin >> n >> m;
	vector<int> x(n + 1);
	x[n] = 1 << 30;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		int pos = lower_bound(x.begin(), x.end(), a) - x.begin() - 1;
		if (pos >= 0) {
			cout << (n - pos) << endl;
			x[pos] = a;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}
