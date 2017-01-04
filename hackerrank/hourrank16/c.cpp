// C.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long LL;

static const LL MOD = 1000000009;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	LL ans = 0;
	if (N <= 10) {
		int d[10][10], f[10][10] = {};
		memset(d, -1, sizeof(d));
		for (int i = 0; i < N; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			d[u - 1][v - 1] = d[v - 1][u - 1] = w;
			f[u - 1][v - 1] = f[v - 1][u - 1] = (1 << (u - 1)) | (1 << (v - 1));
		}
		for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					if (d[i][k] > 0 && d[k][j] > 0) {
						int a = d[i][k] + d[k][j];
						if (d[i][j] < 0 || a < d[i][j]) {
							d[i][j] = d[i][k] + d[k][j];
							f[i][j] = f[i][k] | f[k][j];
						}
					}
				}
			}
		}
		int seq[10] = { 0,1,2,3,4,5,6,7,8,9 };
		do {
			int b = 0;
			for (int i = 0; i < N; ++i) {
				int k = seq[i];
				for (int j = 0; j < N; ++j) {
					if (k != j && (f[k][j] & b) == 0) {
						ans += d[k][j];
					}
				}
				b |= 1 << k;
			}
			ans %= MOD;
		} while (next_permutation(seq, seq + N));
	}
	cout << ans << endl;
	return 0;
}
