// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(m), d(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> c[i] >> d[i];
	}
	for (int i = 0; i < n; ++i) {
		int k = 0;
		for (int j = 1; j < m; ++j) {
			if (abs(a[i] - c[j]) + abs(b[i] - d[j]) < abs(a[i] - c[k]) + abs(b[i] - d[k])) {
				k = j;
			}
		}
		cout << (k + 1) << endl;
	}
	return 0;
}
