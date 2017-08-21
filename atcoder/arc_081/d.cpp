// D.

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>

using namespace std;

static const long long MOD = 1000000007;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string s[2];
	cin >> s[0] >> s[1];
	int st = -1;
	long long ans = 1;
	for (int i = 0; i < n; ++i) {
		if (s[0][i] == s[1][i]) {
			switch (st) {
			case 1:
				ans *= 2;
				break;
			case 2:
				break;
			default:
				ans = 3;
				break;
			}
			st = 1;
		} else {
			switch (st) {
			case 1:
				ans *= 2;
				break;
			case 2:
				ans *= 3;
				break;
			default:
				ans = 6;
				break;
			}
			st = 2;
			++i;
		}
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}
