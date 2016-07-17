// B. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

int main(int argc, char *argv[])
{
	LL N, X;
	cin >> N >> X;
	LL ans = 3 * (N - gcd(X, N - X));
	cout << ans << endl;
	return 0;
}
