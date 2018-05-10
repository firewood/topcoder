// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, x, mn = 1LL << 30, m;
	cin >> n >> x;
	for (int i = 0; i < n; ++i) {
		cin >> m;
		x -= m;
		mn = min(mn, m);
	}
	int ans = n + x / mn;
	cout << ans << endl;
	return 0;
}
