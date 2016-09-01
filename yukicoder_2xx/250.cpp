#include <iostream>

using namespace std;
typedef long long LL;

LL ncr(LL n, LL r) {
	if (r > n / 2) {
		return ncr(n, n - r);
	}
	LL x = 1;
	for (LL i = 1; i <= r; ++i) {
		x = x * (n - i + 1) / i;
		if (x > 1e16) {
			break;
		}
	}
	return x;
}

long long nHr(int n, int r) { return r == 0 ? 1 : ncr(n + r - 1, r); }

int main(int argc, char *argv[]) {
	LL Q, D, X, T;
	cin >> Q;
	while (Q--) {
		cin >> D >> X >> T;
		LL a = ncr(X + D - 1, X);
		LL b = nHr(X + 1, D - 1);
		if (a != b) {
			++a;
		}
		cout << (a <= T ? "AC" : "ZETUBOU") << endl;
	}
	return 0;
}
