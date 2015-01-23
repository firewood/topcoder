#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>

using namespace std;

#define MOD 1000000000LL
typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	LL N, M;
	stringstream ss(s);
	ss >> N;
	getline(cin, s);
	M = atoi(s.c_str());
	N /= 1000;
	N %= M;
	LL a[10000] = {};
	for (LL i = 0; i < N; ++i) {
		a[i] = M - N + i + 1;
	}
	for (LL i = 1; i <= N; ++i) {
		LL b = i;
		for (LL j = 0; b > 1 && j < N; ++j) {
			LL g = gcd(a[j], b);
			a[j] /= g, b /= g;
		}
	}
	LL ans = 1;
	for (LL i = 0; i < N; ++i) {
		ans = (ans * a[i]) % MOD;
	}
	cout << ans << endl;
	return 0;
}
