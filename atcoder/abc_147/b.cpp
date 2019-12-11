// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < (int)s.length() / 2; ++i) {
		ans += s[i] != s[s.length() - i - 1];
	}
	cout << ans << endl;
	return 0;
}
