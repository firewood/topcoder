// B.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t = s.substr(0, n / 2) + s.substr(0, n / 2);
	string ans = s == t ? "Yes" : "No";
	cout << ans << endl;
	return 0;
}
