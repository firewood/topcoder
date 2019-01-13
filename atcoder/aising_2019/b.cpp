// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, a, b, x = 0, y = 0, z = 0, p;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		cin >> p;
		if (p <= a) {
			++x;
		} else if (p <= b) {
			++y;
		} else {
			++z;
		}
	}
	int ans = min({ x, y, z });
	cout << ans << endl;
	return 0;
}
