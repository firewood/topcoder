//
// Facebook Hacker Cup 2018 Round 1
// A. Let It Flow
//

/*
Constraints

1 <= T <= 100
1 <= N <= 1000

*/

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		string g[3];
		cin >> g[0] >> g[1] >> g[2];
		LL left[3][1002] = { 1 };
		LL utod[2][1002] = {};
		LL dtou[2][1002] = {};
		for (int i = 0; i < n; ++i) {
			if (g[1][i] != '#') {
				dtou[0][i + 1] = left[1][i];
				utod[1][i + 1] = left[1][i];
			}
			if (g[0][i] != '#') {
				utod[0][i + 1] = left[0][i];
				left[0][i + 1] = dtou[0][i + 1];
			}
			if (g[2][i] != '#') {
				dtou[1][i + 1] = left[2][i];
				left[2][i + 1] = utod[1][i + 1];
			}
			if (g[1][i] != '#') {
				left[1][i + 1] = (utod[0][i + 1] + dtou[1][i + 1]) % MOD;
			}
		}
		LL ans = left[2][n];
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
