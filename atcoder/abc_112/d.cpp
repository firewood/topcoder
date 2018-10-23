// D.

#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	int n, m, ans = 0;
	cin >> n >> m;
	int mm = (int)sqrt(m);
	for (int i = 1; i <= mm; ++i) {
		int a = m / i;
		if (a * i == m) {
			if (a >= n) {
				ans = max(ans, i);
			}
			if (i >= n) {
				ans = max(ans, a);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
