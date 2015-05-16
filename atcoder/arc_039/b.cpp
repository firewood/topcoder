// B. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long LL;

#define COMBSZ 1024
const LL MOD = 1000000007;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	stringstream ss(s);
	LL N, K;
	ss >> N >> K;

	LL C[COMBSZ][COMBSZ] = {};
	for (LL i = 0; i < COMBSZ; ++i) {
		C[i][0] = 1;
		for (LL j = 1; j <= i; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}

	LL ans = 0;
	if (K < N) {
		ans = C[N + K - 1][N - 1];
	} else {
		ans = C[N][K % N];
	}
	cout << ans << endl;
	return 0;
}
