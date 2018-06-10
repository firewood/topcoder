// D.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[])
{
	LL n, c;
	cin >> n >> c;
	LL d[30][30];
	for (LL i = 0; i < c; ++i) {
		for (LL j = 0; j < c; ++j) {
			cin >> d[i][j];
		}
	}
	LL cost[3][30] = {};
	for (LL i = 0; i < n; ++i) {
		for (LL j = 0; j < n; ++j) {
			LL color;
			cin >> color;
			--color;
			LL r = (i + j) % 3;
			for (LL k = 0; k < c; ++k) {
				cost[r][k] += d[color][k];
			}
		}
	}
	LL ans = 1LL << 60;
	for (LL i = 0; i < c; ++i) {
		for (LL j = 0; j < c; ++j) {
			if (i == j) continue;
			for (LL k = 0; k < c; ++k) {
				if (i == k || j == k) continue;
				LL seq[3] = { 0, 1, 2 };
				do {
					ans = min(ans, cost[seq[0]][i] + cost[seq[1]][j] + cost[seq[2]][k]);
				} while (next_permutation(seq, seq + 3));
			}
		}
	}
	cout << ans << endl;
	return 0;
}
