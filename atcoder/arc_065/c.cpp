// C.

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

int main(int argc, char *argv[])
{
	string s;
	cin >> s;
	bool ans = true;
	for (int i = 0; i != s.length(); ) {
		if (i <= (s.length() - 5)) {
			if (strncmp(s.c_str() + i, "dream", 5) == 0) {
				if (i <= (s.length() - 8)) {
					if (strncmp(s.c_str() + i, "dreamera", 8) == 0) {
						i += 5;
						continue;
					}
				}
				i += 5 + ((i <= (s.length() - 7) && s[i + 5] == 'e' && s[i + 6] == 'r') ? 2 : 0);
				continue;
			}
			if (strncmp(s.c_str() + i, "erase", 5) == 0) {
				i += 5 + ((i <= (s.length() - 6) && s[i + 5] == 'r') ? 1 : 0);
				continue;
			}
		}
		ans = false;
		break;
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
