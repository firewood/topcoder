// Google Code Jam 2013 R1B
// Problem B. Falling Diamonds
// large

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

double solve(int N, int X, int Y)
{
	if (Y < 0) {
		return 0.0;
	}

	int length = abs(X) + abs(Y);
	int i, j, k;
	for (i = 0; i < length; i += 2) {
		N -= i * 2 + 1;
	}
	if (N <= 0) {
		// insufficient
		return 0.0;
	}
	if (N >= (length * 2 + 1)) {
		// full
		return 1.0;
	}
	if (Y >= length) {
		// topmost
		return 0.0;
	}

	double dp[2][10001] = {};
	int f = 0;
	dp[0][0] = 1.0;
	for (i = 0; i < N; ++i) {
		int g = f ^ 1;
		memset(dp+g, 0, sizeof(dp[0]));
		for (j = 0; j <= i; ++j) {
			k = i - j;
			if (j >= length) {
				dp[g][j] += dp[f][j];
			} else if (k >= length) {
				dp[g][j+1] += dp[f][j];
			} else {
				dp[g][j] += dp[f][j] / 2.0;
				dp[g][j+1] += dp[f][j] / 2.0;
			}
		}
		f = g;
	}

	double ans = 0.0;
	for (i = Y+1; i <= N; ++i) {
		ans += dp[f][i];
	}
	return ans;
}

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	if (T <= 0) return 0;

	for (int t = 0; t < T; ++t) {
		int N = 0, X = 0, Y = 0;
		getline(cin, s);
		stringstream ss(s);
		ss >> N >> X >> Y;
		if (N <= 0) {
			break;
		}
		printf("Case #%d: %.7f\n", t+1, solve(N, X, Y));
	}

	return 0;
}

