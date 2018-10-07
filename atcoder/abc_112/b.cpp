// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n, t, ans = 1 << 30;
	bool tle = true;
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		if (b <= t) {
			ans = min(ans, a);
			tle = false;
		}
	}
	if (tle) {
		cout << "TLE" << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}
