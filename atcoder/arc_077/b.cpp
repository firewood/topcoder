// B.

#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int ans = 0;
	string s;
	cin >> s;
	for (int i = 2; i < (int)s.length(); i += 2) {
		if (s.substr(0, i / 2) == s.substr(i / 2, i / 2)) {
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}
