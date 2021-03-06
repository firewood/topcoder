//
// Facebook Hacker Cup 2015 Qualification Round
// A. Cooking the Books
//

#include <algorithm>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	string s;
	getline(cin, s);
	int T = atoi(s.c_str());
	for (int t = 0; t < T; ++t) {
		getline(cin, s);
		string a = s, b = s;
		for (int i = 0; i < s.length(); ++i) {
			for (int j = i + 1; j < s.length(); ++j) {
				if (i == 0 && s[j] == '0') {
					continue;
				}
				string c = s;
				c[i] = s[j], c[j] = s[i];
				if (c < a) {
					a = c;
				}
				if (c > b) {
					b = c;
				}
			}
		}
		cout << "Case #" << (t+1) << ": " << a << " " << b << endl;
	}

	return 0;
}
