// E.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

typedef long long LL;

LL solve(LL n) {
	LL ans = 0;
	if ((n % 2) == 0) {
		n /= 2;
		while (n > 0) {
			n /= 5;
			ans += n;
		}
	}
	return ans;
}

int main(int argc, char* argv[]) {

#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, ans = 0;
		cin >> n;
		if (n < 0) return 0;
		ans = solve(n);
		cout << ans << endl;
	}
	return 0;
}
