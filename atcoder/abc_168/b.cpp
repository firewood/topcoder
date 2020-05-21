// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	int k;
	string s;
	cin >> k;
	cin >> s;
	string ans = s;
	if (s.length() > k) {
		ans = s.substr(0, k) + "...";
	}
	cout << ans << endl;
	return 0;
}
