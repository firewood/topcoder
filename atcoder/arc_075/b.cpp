// B.

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	char cnt[256] = {};
	bool ans = true;
	for (char c : s) {
		if (++cnt[c] >= 2) {
			ans = false;
		}
	}
	cout << (ans ? "yes" : "no") << endl;
	return 0;
}
