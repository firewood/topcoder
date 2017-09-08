// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string s, ans;
	cin >> s;
	for (int i = 0; i < (int)s.length(); i += 2) {
		ans += s[i];
	}
	cout << ans << endl;
	return 0;
}
