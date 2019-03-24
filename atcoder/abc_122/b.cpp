// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int ans = 0, cnt = 0;
	for (char c : s) {
		if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
			++cnt;
			ans = max(ans, cnt);
		} else {
			cnt = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
