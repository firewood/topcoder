// A.

#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <locale>

using namespace std;

int main(int argc, char *argv[]) {
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	--a, --b, --c, --d;
	string s;
	cin >> s;
	s += "##";
	if (a > b) {
		swap(a, b);
		swap(c, d);
	}
	bool ok = true;
	for (int i = a; i < c; ++i) {
		if (s[i + 1] == '.') {
			++i;
		} else if (s[i] == '#') {
			ok = false;
		}
	}
	for (int i = b; i < d; ++i) {
		if (s[i + 1] == '.') {
			++i;
		} else if (s[i] == '#') {
			ok = false;
		}
	}
	if (ok && c > d) {
		ok = false;
		for (int i = b - 1; i < d; ++i) {
			if (s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.') {
				ok = true;
				break;
			}
		}
	}
	cout << (ok ? "Yes" : "No") << endl;
	return 0;
}
