// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	char cnt[256] = {};
	string s;
	cin >> s;
	for (char c : s) {
		cnt[c] += 1;
	}
	string ans = "None";
	for (char c = 'a'; c <= 'z'; ++c) {
		if (!cnt[c]) {
			ans = string(1, c);
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
