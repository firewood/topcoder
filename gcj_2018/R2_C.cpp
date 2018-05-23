// Google Code Jam 2018 Round 2
// Problem C. Costume Change

#include <iostream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef long long LL;

unsigned long long xor128(void)
{
	static unsigned long long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
	unsigned long long t;
	t = (x ^ (x << 11));x = y;y = z;z = w; return(w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

int org[4][4];
int org2[100][100];

int solve(int n) {
	int ans = 1 << 30;
	int mcol = n * 2;
	for (int t = 0; t < 1500000; ++t) {
		int x[4][4];
		int cnt = 0;
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < n; ++c) {
				long long z = xor128();
				if (((z >> 8) & 7) <= 3) {
					x[r][c] = z % mcol;
					cnt += x[r][c] != org[r][c];
				} else {
					x[r][c] = org[r][c];
				}
				for (int p = 0; p < c; ++p) {
					if (x[r][p] == x[r][c]) {
						goto nx;
					}
				}
				for (int q = 0; q < r; ++q) {
					if (x[q][c] == x[r][c]) {
						goto nx;
					}
				}
			}
		}
		ans = min(ans, cnt);
	nx:
		;
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int n;
		cin >> n;
		int ans = 0;
		if (n <= 4) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					int col;
					cin >> col;
					if (col > 0) {
						--col;
					}
					col += n;
					org[i][j] = col;
				}
			}
			ans = solve(n);
		} else {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					cin >> org2[i][j];
				}
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}
