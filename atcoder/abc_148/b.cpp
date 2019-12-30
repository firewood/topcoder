// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	string ans;
	for (int i = 0; i < (int)s.length(); ++i) {
		ans += s[i];
		ans += t[i];
	}
	cout << ans << endl;
	return 0;
}
