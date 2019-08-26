// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int m, d;
	cin >> m >> d;
	int ans = 0;
	for (int i = 4; i <= m; ++i) {
		for (int j = 22; j <= d; ++j) {
			ans += (j % 10) >= 2 && i == (j / 10) * (j % 10);
		}
	}
	cout << ans << endl;
	return 0;
}
