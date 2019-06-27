// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	char prev = 0;
	string ans = "Good";
	for (char c : s) {
		if (c == prev) {
			ans = "Bad";
		}
		prev = c;
	}
	cout << ans << endl;
	return 0;
}
