// C.

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, m, ans;
	cin >> n >> m;
	LL a = min(n, m), b = max(n, m);
	if (a == 1) {
		ans = b == 1 ? 1 : b - 2;
	} else {
		ans = (a - 2) * (b - 2);
	}
	cout << ans << endl;
	return 0;
}
