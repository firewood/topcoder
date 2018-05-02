// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		LL a, b, ans = 0;
		cin >> a >> b;
		if (abs(a - b) > 1) {
			LL c = sqrt(a * b - 1);
			if (c * (c + 1) >= a * b) {
				ans = 2 * c - 2;
			} else {
				ans = 2 * c - 1;
			}
		} else {
			ans = 2 * min(a, b) - 2;
		}
		cout << ans << endl;
	}
	return 0;
}
