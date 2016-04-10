// B. 

#include <iostream>
#include <sstream>

using namespace std;
typedef long long LL;

LL modpow(LL b, LL e, LL m) {
	LL r = 1;
	while (e > 0) {
		if (e & 1) {
			r = (r * b) % m;
		}
		e >>= 1;
		b = (b * b) % m;
	}
	return r;
}

int main(int argc, char *argv[])
{
	LL N, M, P;
	cin >> N >> M >> P;
	LL ans = modpow(N, P, M);
	cout << ans << endl;
	return 0;
}
