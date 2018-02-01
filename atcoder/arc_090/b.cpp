// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b, c, x, ans = 0;
	cin >> a >> b >> c >> x;
	for (int i = 0; i <= a; ++i) {
		for (int j = 0; j <= b; ++j) {
			for (int k = 0; k <= c; ++k) {
				int l = i * 500 + j * 100 + k * 50;
				ans += x == l;
				if (l > x) {
					break;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
