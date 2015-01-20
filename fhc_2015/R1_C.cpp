//
// Facebook Hacker Cup 2015 Round 1
// C. Winning at Sports
//

/*
Constraints

1 <= T <= 100 

Since you always win, the first number in any final score will always be larger than the second.
Both scores will be non-negative integers not exceeding 2000.
*/

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

#define MOD 1000000007LL

static int popcount(LL bits) {
	bits = (bits & 0x5555555555555555LL) + (bits >> 1 & 0x5555555555555555LL);
	bits = (bits & 0x3333333333333333LL) + (bits >> 2 & 0x3333333333333333LL);
	bits = (bits & 0x0f0f0f0f0f0f0f0fLL) + (bits >> 4 & 0x0f0f0f0f0f0f0f0fLL);
	bits = (bits & 0x00ff00ff00ff00ffLL) + (bits >> 8 & 0x00ff00ff00ff00ffLL);
	bits = (bits & 0x0000ffff0000ffffLL) + (bits >> 16 & 0x0000ffff0000ffffLL);
	bits = (bits & 0x00000000ffffffffLL) + (bits >> 32 & 0x00000000ffffffffLL);
	return (int)bits;
}

void solve_bit(int A, int B, int &x, int &y) {
	x = 0, y = 0;
	int C = A + B;
	if (C > 20) {
		return;
	}
	LL M = 1LL << C;
	for (LL i = 0; i < M; ++i) {
		if (popcount(i) != B) {
			continue;
		}
		int a = 0, b = 0;
		bool af = true, bf = true;
		for (LL j = 0; j < C; ++j) {
			if ((1LL << j) & i) {
				++b;
				if (b >= a) {
					af = false;
				}
			} else {
				++a;
				if (b < B && a > b) {
					bf = false;
				}
			}
		}
		if (af) {
			++x;
		}
		if (bf) {
			++y;
		}
	}
}

void solve_dp(int A, int B, int &x, int &y) {
	x = 0, y = 0;
	int C = A + B;

	static int dp_a[4002][4002], dp_b[4002][4002];

	memset(dp_a, 0, sizeof(dp_a));
	dp_a[1][0] = 1;
	for (int t = 2; t <= C; ++t) {
		for (int i = 0; i <= 2000; ++i) {
			int j = t - i - 1;
			if (j < 0) {
				break;
			}
			int p = dp_a[i][j];
			if (j < i) {
				dp_a[i + 1][j] = (dp_a[i + 1][j] + p) % MOD;
				if (j + 1 < i) {
					dp_a[i][j + 1] = (dp_a[i][j + 1] + p) % MOD;
				}
			}
		}
	}

	memset(dp_b, 0, sizeof(dp_b));
	dp_b[0][0] = 1;
	for (int t = 1; t <= C; ++t) {
		for (int i = 0; i <= 2000; ++i) {
			int j = t - i - 1;
			if (j < 0) {
				break;
			}
			int p = dp_b[i][j];
			if (j >= B) {
				dp_b[i][j + 1] = (dp_b[i][j + 1] + p) % MOD;
				dp_b[i + 1][j] = (dp_b[i + 1][j] + p) % MOD;
			} else if (i >= 0 && j >= 0 && i <= 2000 && j <= 2000 && i <= j) {
				dp_b[i][j + 1] = (dp_b[i][j + 1] + p) % MOD;
				if (j >= B || i + 1 <= j) {
					dp_b[i + 1][j] = (dp_b[i + 1][j] + p) % MOD;
				}
			}
		}
	}

	x = dp_a[A][B];
	y = dp_b[A][B];
}

int main(int argc, char *argv[]) {
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		getline(cin, s);
		stringstream ss(s);
		int A, B;
		ss >> A >> B;
		B = -B;
		int x, y;
		solve_dp(A, B, x, y);
		cout << "Case #" << (t+1) << ": " << x << " " << y << endl;
	}

#if 0
	for (int a = 1; a < 15; ++a) {
		for (int b = 0; b < a; ++b) {
			if (a + b <= 20) {
				int p, q, r, s;
				solve_bit(a, b, p, q);
				solve_dp(a, b, r, s);
				printf("%d %d -> %d %d\n", a, b, p, q);
				if (p != r || q != s) {
					printf("%d %d %d %d %d %d\n", a, b, p, q, r, s);
					break;
				}
			}
		}
	}
#endif

	return 0;
}
