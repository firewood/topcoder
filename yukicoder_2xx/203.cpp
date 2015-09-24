#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int cnt = 0, ans = 0;
	for (char c : a + b) {
		if (c == 'o') {
			++cnt;
			ans = max(ans, cnt);
		} else {
			cnt = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
