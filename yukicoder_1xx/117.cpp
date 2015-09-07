#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;
typedef long long LL;
const LL MOD = 1000000007;

LL extgcd(LL a, LL b, LL &x, LL &y) {
	LL d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	} else {
		x = 1, y = 0;
	}
	return d;
}

LL modinv(LL a, LL m) {
	LL x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

LL modpow(LL x, LL n, LL mod)
{
	LL a = 1;
	for (; n > 0; n >>= 1) {
		if (n & 1) a = (a * x) % mod;
		x = (x * x) % mod;
	}
	return a;
}

int main(int argc, char *argv[])
{
	LL T;
	string s;
	{
		getline(cin, s);
		stringstream ss(s);
		ss >> T;
	}

	LL fact[2000001];
	fact[0] = 1;
	for (LL a = 1; a <= 2000000; ++a) {
		fact[a] = (fact[a - 1] * a) % MOD;
	}
	for (int t = 0; t < T; ++t) {
		char type;
		LL n, k;
		getline(cin, s);
		sscanf(s.c_str(), "%c(%lld,%lld)", &type, &n, &k);
		LL a = 0, b = 1, c = 1;
		switch (type) {
		case 'C':
			if (k <= n) {
				a = fact[n];
				b = modinv(fact[k], MOD);
				c = modinv(fact[n - k], MOD);
			}
			break;
		case 'P':
			if (k <= n) {
				a = (fact[n] * fact[k]) % MOD;
				b = modinv(fact[k], MOD);
				c = modinv(fact[n - k], MOD);
			}
			break;
		case 'H':
			if (n == 0) {
				a = k == 0;
			} else {
				a = fact[n + k - 1];
				b = modinv(fact[k], MOD);
				c = modinv(fact[n - 1], MOD);
			}
			break;
		}
		cout << ((((a * b) % MOD) * c) % MOD) << endl;
	}
	return 0;
}
