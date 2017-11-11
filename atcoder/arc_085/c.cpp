// C.

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL n, m, ans;
	cin >> n >> m;
	ans = (100 * (n - m) + 1900 * m) * (1LL << m);
	cout << ans << endl;
	return 0;
}
