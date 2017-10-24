// C.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int left = 0, right = (int)s.length() - 1, ans = 0;
	while (left < right) {
		while (left < right && s[left] == 'x') {
			++left;
			if (s[right] == 'x') {
				--right;
			} else {
				++ans;
			}
		}
		while (left < right && s[right] == 'x') {
			--right;
			++ans;
		}
		if (left < right && s[left] != s[right]) {
			ans = -1;
			break;
		}
		++left;
		--right;
	}
	cout << ans << endl;
	return 0;
}
