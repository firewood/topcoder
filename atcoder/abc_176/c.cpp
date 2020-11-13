// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

typedef long long LL;

int main(int argc, char* argv[]) {
	LL n, a, mx = 0, ans = 0;
	cin >> n;
	for (LL i = 0; i < n; ++i) {
		cin >> a;
		mx = max(mx, a);
		ans += mx - a;
	}
	cout << ans << endl;
	return 0;
}
