// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n, ans = 1 << 30;
	cin >> n;
	for (int a = 1; a * a <= n; ++a) {
		for (int b = a; a * b <= n; ++b) {
			ans = min(ans, b - a + n - a * b);
		}
	}
	cout << ans << endl;
	return 0;
}
