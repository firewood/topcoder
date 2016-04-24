#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int a, b, c;
	cin >> a >> b >> c;
	if (a != c && ((b > a && b > c) || (b < a && b < c))) {
		cout << "INF" << endl;
	} else {
		int ans = 0;
		for (int p = 2; p <= 1000; ++p) {
			int x = a % p, y = b % p, z = c % p;
			ans += x != z && ((y > x && y > z) || (y < x && y < z));
		}
		cout << ans << endl;
	}
	return 0;
}
