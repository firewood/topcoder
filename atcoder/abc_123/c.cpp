// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, cap[5];
	cin >> n;
	for (int i = 0; i < 5; ++i) {
		cin >> cap[i];
	}
	LL m = *min_element(cap, cap + 5);
	LL ans = 4 + (n + m - 1) / m;
	cout << ans << endl;
	return 0;
}
