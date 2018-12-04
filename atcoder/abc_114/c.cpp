// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
	long long n, len = 0, ans = 0;
	cin >> n;
	char d[16] = {};
	while (true) {
		int pos = 12;
		while (true) {
			if (!d[pos]) {
				++len;
				d[pos] = '3';
				break;
			} else if (d[pos] == '3') {
				d[pos] = '5';
				break;
			} else if (d[pos] == '5') {
				d[pos] = '7';
				break;
			} else if (d[pos] == '7') {
				d[pos] = '3';
				--pos;
			}
		}
		if (atoll(d + 13 - len) > n) {
			break;
		}
		int f = 0;
		for (int i = 0; i < len; ++i) {
			if (d[12 - i] == '3') f |= 1;
			else if (d[12 - i] == '5') f |= 2;
			else f |= 4;
		}
		ans += f == 7;
	}
	cout << ans << endl;
	return 0;
}
