// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, d, x, y, ans = 0;
	cin >> n >> d;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		ans += (x * x + y * y) <= d * d;
	}
	cout << ans << endl;
	return 0;
}
