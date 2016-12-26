// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
	int x, y;
	cin >> x >> y;
	int ans = 1 << 30;
	for (int a = -1; a <= 1; a += 2) {
		for (int b = -1; b <= 1; b += 2) {
			int p = x * a, q = y * b;
			if (p <= q) {
				ans = min(ans, (a < 0) + (b < 0) + q - p);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
