// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL ans = 0;
	LL a, b, c;
	cin >> a >> b >> c;
	LL x = min(a, c);
	ans += x;
	a -= x;
	c -= x;
	LL y = min(b, c);
	ans += 2 * y;
	b -= y;
	c -= y;
	ans += c > 0;
	ans += b;
	cout << ans << endl;
	return 0;
}
