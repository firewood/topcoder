// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

typedef long long LL;

LL solve(LL n, LL a, LL b) {
	LL ans = b - 1;
	if (((b - a) % 2) == 0) {
		ans = min(ans, (b - a) / 2);
	} else {
		ans = min(ans, a + (b - a) / 2);
	}
	return ans;
}

int main(int argc, char* argv[]) {
	const LL INF = 1LL << 60;
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL n = -1, a, b;
		cin >> n >> a >> b;
		if (n < 0) return 0;
		LL ans = min(solve(n, a, b), solve(n, n - b + 1, n - a + 1));
		cout << ans << endl;
	}
	return 0;
}
