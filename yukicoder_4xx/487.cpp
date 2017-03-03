#include <iostream>

typedef long long LL;

static LL modpow(LL b, LL e, LL m) {
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

int main(int argc, char *argv[]) {
	int M;
	std::cin >> M;
	LL ans = (2017 + modpow(2017 * 2017, 2017, M)) % M;
	std::cout << ans << std::endl;
	return 0;
}
