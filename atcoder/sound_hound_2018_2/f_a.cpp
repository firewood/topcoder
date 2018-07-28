// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL c, d, ans = 0;
	cin >> c >> d;
	for (LL low = 140, high = 170; low < d; low *= 2, high *= 2) {
		LL x = max(low, c);
		LL y = min(high, d);
		ans += max(0LL, y - x);
	}
	cout << ans << endl;
	return 0;
}
