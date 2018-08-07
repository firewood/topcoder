// B.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	bool ans = s[0] == 'A';
	int cnt = 0;
	for (int i = 1; i < (int)s.length(); ++i) {
		if (s[i] == 'C') {
			if (cnt == 0 && i >= 2 && i <= (s.length() - 2)) {
				++cnt;
			} else {
				ans = false;
			}
		} else if (!islower(s[i])) {
			ans = false;
		}
	}
	cout << ((ans && cnt == 1) ? "AC" : "WA") << endl;
	return 0;
}
