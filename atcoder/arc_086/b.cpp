// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, a, ans = 1 << 30;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		int cnt = 0;
		while ((a % 2) == 0) {
			++cnt;
			a /= 2;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
