// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, h, ans = 0, m = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> h;
		ans += h >= m;
		m = max(m, h);
	}
	cout << ans << endl;
	return 0;
}
