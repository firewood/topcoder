// Google Code Jam 2013 R1B
// Problem B. Falling Diamonds
// small

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

static inline int popcount(unsigned int b)
{
#ifdef __GNUC__
	return __builtin_popcount(b);
#elif _MSC_VER >= 1400
	return __popcnt(b);
#else
	b = (b & 0x55555555) + (b >> 1 & 0x55555555);
	b = (b & 0x33333333) + (b >> 2 & 0x33333333);
	b = (b & 0x0F0F0F0F) + (b >> 4 & 0x0F0F0F0F);
	b += b >> 8;
	b += b >> 16;
	return b & 0x3F;
#endif
}

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

	int A = 1 << N;
	int C = 0;
	for (i = 0; i < A; ++i) {
		int c = popcount(i);
		c += max(0, N - c - length);
		C += c > Y;
	}

	return (double)C / (double)A;
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

