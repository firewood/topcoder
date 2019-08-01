// C.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int n = (int)s.length();
	int ans = n;
	for (int i = 0; i < 2; ++i) {
		int cnt = 0;
		for (int j = 0; j < n; ++j) {
			cnt += ((i + j) % 2) != (s[j] - '0');
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
