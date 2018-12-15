// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

int main(int argc, char *argv[]) {
	LL ans = 0;
	string s;
	cin >> s;
	int len = (int)s.length(), w = 0;
	for (int i = len - 1; i >= 0; --i) {
		if (s[i] == 'W') {
			++w;
		} else {
			ans += w;
		}
	}
	cout << ans << endl;
	return 0;
}
