// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
	int n, mn = 1 << 30, p, ans = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p;
		if (p <= mn) {
			++ans;
		}
		mn = min(mn, p);
	}
	cout << ans << endl;
	return 0;
}
