// Google Code Jam 2016 Qualification Round
// Problem A. Counting Sheep

#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

LL solve(LL N) {
	LL f = 0, x;
	for (x = N; ; x += N) {
		char temp[16];
		sprintf(temp, "%lld", x);
		for (int i = 0; temp[i]; ++i) {
			f |= (1 << (temp[i] - '0'));
		}
		if (f >= 1023) {
			break;
		}
	}
	return x;
}

int main(int argc, char *argv[]) {
	LL T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		LL N;
		cin >> N;
		if (N == 0) {
			cout << "Case #" << t << ": INSOMNIA" << endl;
		} else {
			cout << "Case #" << t << ": " << solve(N) << endl;
		}
	}
	return 0;
}
