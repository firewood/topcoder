// A.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	string s;
	cin >> s;
	int ans = 0;
	for (char c : s) {
		ans += c - '0';
	}
	cout << ans << endl;
	return 0;
}
