#include <iostream>
#include <algorithm>

#define COMBSZ 3002

using namespace std;
typedef long long LL;

int main(int argc, char *argv[]) {
	static LL C[COMBSZ][COMBSZ];
	for (LL i = 0; i < COMBSZ; ++i) {
		C[i][0] = 1;
		for (LL j = 1; j <= i; ++j) {
			LL c = C[i - 1][j - 1] + C[i - 1][j];
			C[i][j] = min(c, 1LL << 50);
		}
	}

	LL Q, D, X, T;
	cin >> Q;
	while (Q--) {
		cin >> D >> X >> T;
		LL a = C[X + D - 1][X];
		cout << (a <= T ? "AC" : "ZETUBOU") << endl;
	}
	return 0;
}
