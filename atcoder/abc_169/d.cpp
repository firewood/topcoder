// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;

int main(int argc, char* argv[]) {
	LL n, ans = 0;
	cin >> n;
	for (LL x = 2; x <= 1000000; ++x) {
		int c = 0, d = 1;
		while ((n % x) == 0) {
			n /= x;
			if (++c == d) {
				++ans;
				c = 0;
				++d;
			}
		}
	}
	if (n > 1) {
		++ans;
	}
	cout << ans << endl;
	return 0;
}
