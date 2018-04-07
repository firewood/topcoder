// Google Code Jam 2018 Qualification Round
// Problem A. Saving The Universe Again

#include <iostream>
#include <sstream>

using namespace std;

typedef long long LL;

int solve(LL d, string s) {
	for (int t = 0; ; ++t) {
			LL sum = 0;
		LL power = 1;
		for (char c : s) {
			if (c == 'C') {
				power *= 2;
			}
			if (c == 'S') {
				sum += power;
			}
		}
		if (sum <= d) {
			return t;
		}
		int pos = (int)s.rfind("CS");
		if (pos < 0) {
			break;
		}
		s = s.substr(0, pos) + "SC" + s.substr(pos + 2, s.length() - pos - 2);
	}
	return -1;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		LL d;
		string s;
		cin >> d >> s;
		int ans = solve(d, s);
		if (ans < 0) {
			cout << "Case #" << t << ": IMPOSSIBLE" << endl;
		} else {
			cout << "Case #" << t << ": " << ans << endl;
		}
	}
	return 0;
}
