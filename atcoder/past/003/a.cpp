// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <string>
#include <locale>

using namespace std;

int main() {
	string s, t;
	cin >> s >> t;
	if (s == t) {
		cout << "same" << endl;
	} else {
		for (int i = 0; i < s.length(); ++i) {
			s[i] = toupper(s[i]);
		}
		for (int i = 0; i < t.length(); ++i) {
			t[i] = toupper(t[i]);
		}
		if (s == t) {
			cout << "case-insensitive" << endl;
		} else {
			cout << "different" << endl;
		}
	}
	return 0;
}
