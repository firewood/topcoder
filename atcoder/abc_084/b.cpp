// B.

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	bool ok = s.length() == a + 1 + b;
	if (ok) {
		for (int i = 0; i < a; ++i) {
			if (s[i] < '0' || s[i] > '9') {
				ok = false;
			}
		}
		if (s[a] != '-') {
			ok = false;
		}
		for (int i = a + 1; i < a + 1 + b; ++i) {
			if (s[i] < '0' || s[i] > '9') {
				ok = false;
			}
		}
	}
	cout << (ok ? "Yes" : "No") << endl;
	return 0;
}
