// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n;
	vector<int> x(n), y(n), h(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i] >> h[i];
		if (h[i] > 0) {
			m = i;
		}
	}
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			int h1 = h[m] + abs(i - x[m]) + abs(j - y[m]);
			bool ok = true;
			for (int k = 0; k < n; ++k) {
				int h2 = max(0, h1 - abs(i - x[k]) - abs(j - y[k]));
				if (h2 != h[k]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				cout << i << " " << j << " " << h1 << endl;
				return 0;
			}
		}
	}
	return 0;
}
