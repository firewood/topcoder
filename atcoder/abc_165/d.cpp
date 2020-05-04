// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

LL solve(LL a, LL b, LL n) {
	LL x = min(n, b - 1);
	LL p = (a * x) / b;
	LL q = a * (x / b);
	return p - q;
}

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL a = -1, b, n;
		cin >> a >> b >> n;
		if (a < 0) return 0;
		LL ans = solve(a, b, n);
		cout << ans << endl;
	}
	return 0;
}
