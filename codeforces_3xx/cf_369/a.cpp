// A. 

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
	int N;
	cin >> N;
	string s[1000];
	int ans = -1;
	for (int i = 0; i < N; ++i) {
		cin >> s[i];
		if ((int)s[i].find("OO") >= 0) {
			ans = i;
		}
	}
	if (ans < 0) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for (int i = 0; i < N; ++i) {
			string x = s[i];
			if (i == ans) {
				int pos = s[i].find("OO");
				x = x.substr(0, pos) + "++" + x.substr(pos + 2);
			}
			cout << x << endl;
		}
	}
	return 0;
}
