// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string s, t;
	cin >> s >> t;
	int len = (int)s.length();
	int ans = 0;
	for (int i = 0; i < len; ++i) {
		ans += s[i] != t[i];
	}
	cout << ans << endl;
	return 0;
}
