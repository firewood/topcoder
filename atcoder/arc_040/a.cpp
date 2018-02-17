// A.

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n, r = 0, b = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (char c : s) {
			r += c == 'R';
			b += c == 'B';
		}
	}
	if (r > b) {
		cout << "TAKAHASHI" << endl;
	} else if (b > r) {
		cout << "AOKI" << endl;
	} else {
		cout << "DRAW" << endl;
	}
	return 0;
}
