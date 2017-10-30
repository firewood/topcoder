// B.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n, k, ans = 1 << 30;
	cin >> n >> k;
	for (int i = 0; i <= n; ++i) {
		int x = 1;
		for (int j = 0; j < n; ++j) {
			if (j < i) {
				x *= 2;
			} else {
				x += k;
			}
		}
		ans = min(ans, x);
	}
	cout << ans << endl;
	return 0;
}
