// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	bool ans = false;
	for (int i = 0; i + m <= n; ++i) {
		for (int j = 0; j + m <= n; ++j) {
			bool ok = true;
			for (int k = 0; k < m; ++k) {
				if (a[i + k].substr(j, m) != b[k]) {
					ok = false;
				}
			}
			if (ok) {
				ans = true;
			}
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}
