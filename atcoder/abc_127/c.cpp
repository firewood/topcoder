// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, m, l, r;
	cin >> n >> m;
	int left = 1, right = n;
	for (int i = 0; i < m; ++i) {
		cin >> l >> r;
		left = max(left, l);
		right = min(right, r);
	}
	int ans = max(0, right - left + 1);
	cout << ans << endl;
	return 0;
}
