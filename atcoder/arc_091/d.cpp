// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL n, k, ans = 0;
	cin >> n >> k;
	for (LL b = k + 1; b <= n; ++b) {
		LL c = n / b;
		ans += (b - k) * c;
		LL r = n % b;
		if (r >= k) {
			ans += k ? (r - k + 1) : r;
		}
	}
	cout << ans << endl;
	return 0;
}
