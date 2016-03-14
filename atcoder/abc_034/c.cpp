// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

static const int MOD = 1000000007;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

struct modll {
	long long x;
	modll() { }
	modll(long long _x) : x(_x) { }
	operator int() const { return (int)x; }
	modll operator+(const modll &r) { return (x + r.x) % MOD; }
	modll operator+=(const modll &r) { return x = (x + r.x) % MOD; }
	modll operator-(const modll &r) { return (x + MOD - r.x) % MOD; }
	modll operator-=(const modll &r) { return x = (x + MOD - r.x) % MOD; }
	modll operator*(const modll &r) { return (x * r.x) % MOD; }
	modll operator*(int r) { return (x * r) % MOD; }
	modll operator*=(const modll &r) { return x = (x * r.x) % MOD; }
};

#define COMBSZ 1024

int main(int argc, char *argv[])
{
	int W, H;
	cin >> W >> H;
	--W, --H;

	modll C[COMBSZ][COMBSZ];
	for (int i = 0; i < COMBSZ - 1; ++i) {
		C[i][0] = 1, C[i][i+1] = 0;
		for (int j = 1; j <= i; ++j) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	cout << C[W + H][W] << endl;
	return 0;
}
