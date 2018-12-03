// B.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	int len = (int)s.length();
	int ans = 999;
	for (int i = 0; i <= len - 3; ++i) {
		int n = atoi(s.substr(i, 3).c_str());
		ans = min(ans, abs(753 - n));
	}
	cout << ans << endl;
	return 0;
}
