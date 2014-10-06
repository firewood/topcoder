
// A. 

#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string t, s;
	getline(cin, t);
	getline(cin, s);

	string k = " qwertyuiop asdfghjkl; zxcvbnm,./ ";
	string ans;
	int m = t[0] == 'R' ? -1 : 1;
	for (int i = 0; i < (int)s.length(); ++i) {
		int pos = k.find(s[i]);
		if (k[pos + m] == ' ') {
			ans += k[pos];
		} else {
			ans += k[pos + m];
		}
	}
	cout << ans << endl;

	return 0;
}

