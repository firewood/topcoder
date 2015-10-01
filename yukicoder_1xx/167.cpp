#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;

LL modpow(LL x, LL n, LL mod)
{
	LL a = 1;
	for (LL k = x; n > 0; n >>= 1, k = (k*k) % mod) {
		if (n & 1) {
			a = (a*k) % mod;
		}
	}
	return a;
}

int main(int argc, char *argv[])
{
	string N, M;
	cin >> N >> M;
	int nlen = (int)N.length();
	int mlen = (int)M.length();
	LL n = atoi(N.substr(max(0, nlen - 4), 4).c_str());
	LL m = atoi(M.substr(max(0, mlen - 4), 4).c_str());
	if (mlen > 4 && m == 0) {
		m = 10000;
	}
	LL ans = modpow(n, m, 10);
	cout << ans << endl;
	return 0;
}
