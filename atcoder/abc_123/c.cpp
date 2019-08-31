// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, a, b, c, d, e;
	cin >> n >> a >> b >> c >> d >> e;
	LL ans = (n + a - 1) / a;
	ans = 1 + max(ans, (n + b - 1) / b);
	ans = 1 + max(ans, (n + c - 1) / c);
	ans = 1 + max(ans, (n + d - 1) / d);
	ans = 1 + max(ans, (n + e - 1) / e);
	cout << ans << endl;
	return 0;
}
