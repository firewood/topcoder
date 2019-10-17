// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	while (true) {
		LL n = -1, ans = 1LL << 60;
		cin >> n;
		if (n <= 0) break;
		for (LL i = 1; i * i <= n; ++i) {
			if ((n % i) == 0) {
				ans = min(ans, (LL)to_string(n / i).length());
			}
		}
		cout << ans << endl;
	}
	return 0;
}
