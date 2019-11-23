// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
#ifdef _MSC_VER
	while (true)
#endif
	{
		LL m = -1, d, c, digits = 0, sum = 0;
		cin >> m;
		if (m < 0) return 0;
		for (LL i = 0; i < m; ++i) {
			cin >> d >> c;
			digits += c;
			sum += d * c;
		}
		LL ans = digits - 1 + (sum - 1) / 9;
		cout << ans << endl;
	}
	return 0;
}
