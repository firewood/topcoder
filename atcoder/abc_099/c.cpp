// C.

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	int ans = 1 << 30;
	for (int i = 0; i <= n; ++i) {
		auto count = [](int f, int r) {
			int c = 0;
			for (int j = f; r > 0; j *= f) {
				int k = r % j;
				c += k / (j / f);
				r -= k;
			}
			return c;
		};
		ans = min(ans, count(6, i) + count(9, n - i));
	}
	cout << ans << endl;
	return 0;
}
