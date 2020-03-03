// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
	int n, m;
	cin >> n >> m;
	int s[5], c[5];
	for (int i = 0; i < m; ++i) {
		cin >> s[i] >> c[i];
	}
	int ans = -1;
	for (int x = 0; x <= 999; ++x) {
		char w[16];
		snprintf(w, 16, "%d", x);
		if (strlen(w) != n) continue;
		bool ok = true;
		for (int i = 0; i < m; ++i) {
			if (w[s[i] - 1] != (c[i] + '0')) {
				ok = false;
			}
		}
		if (ok) {
			ans = x;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
