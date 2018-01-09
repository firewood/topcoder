// A.

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	long long a, k, ans = 0;
	cin >> a >> k;
	if (k) {
		while (a < 2 * 1e12) {
			++ans;
			if ((double)a * k >= 2 * 1e12) {
				break;
			}
			a += (1 + k * a);
		}
	} else {
		ans = 2 * 1e12 - a;
	}
	cout << ans << endl;
	return 0;
}
