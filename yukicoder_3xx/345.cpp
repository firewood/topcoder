#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	unsigned int ans = -1;
	for (int i = 1; i != s.length(); ++i) {
		if (s[i] == 'w') {
			int a = s.substr(0, i).rfind('c');
			if (a >= 0) {
				int b = s.substr(i + 1).find('w');
				if (b >= 0) {
					ans = min(ans, (unsigned)(i - a + b + 2));
				}
			}
		}
	}
	cout << (int)ans << endl;
	return 0;
}
