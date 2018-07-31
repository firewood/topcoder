// B. 

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int n, x;
	cin >> n >> x;
	int a[2][100002] = {};
	for (int i = 0; i < n; ++i) {
		int y;
		cin >> y;
		a[0][y] += 1;
		if (y != (x & y)) {
			a[1][x & y] += 1;
		}
	}
	int ans = -1;
	for (int i = 0; i <= 100000; ++i) {
		if (a[0][i] >= 2) {
			ans = 0;
			break;
		}
		if (a[0][i] >= 1 && a[1][i] >= 1) {
			ans = 1;
		}
		if (a[1][i] >= 2) {
			if (ans < 0) {
				ans = 2;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
