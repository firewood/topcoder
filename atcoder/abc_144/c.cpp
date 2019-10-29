// C.

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
		LL n = -1;
		cin >> n;
		if (n <= 0) return 0;
		LL ans = n - 1;
		for (LL a = 2; a <= 1000000; ++a) {
			if ((n % a) == 0) {
				LL b = n / a;
				ans = min(ans, a - 1 + b - 1);
			}
		}
		cout << ans << endl;
	}
	return 0;
}
