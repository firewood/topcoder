// Google Code Jam 2017 Qualification Round
// Problem B. Tidy Numbers

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL solve(LL n) {
	for (LL d = 1; d <= n; d *= 10) {
		LL a = (n / d) % 10, b = (n / d / 10) % 10;
		if (a < b) {
			LL c = n - (n % (d * 10));
			n = c - 1;
		}
	}
	return n;
}

int main(int argc, char *argv[]) {
	LL T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		LL N;
		cin >> N;
		cout << "Case #" << t << ": " << solve(N) << endl;
	}
	return 0;
}
